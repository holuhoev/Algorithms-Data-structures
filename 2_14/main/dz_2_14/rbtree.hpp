////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Реализация классов красно-черного дерева
/// \author    Sergey Shershakov
/// \version   0.1.0
/// \date      01.05.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// "Реализация" (шаблонов) методов, описанных в файле rbtree.h
///
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>        // std::invalid_argument


namespace xi
{


//==============================================================================
// class RBTree::node
//==============================================================================

template<typename Element, typename Compar>
RBTree<Element, Compar>::Node::~Node()
{
    if (_left)
        delete _left;
    if (_right)
        delete _right;
}


template<typename Element, typename Compar>
typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::Node::setLeft(Node* lf)
{
    // предупреждаем повторное присвоение
    if (_left == lf)
        return nullptr;

    // если новый левый — действительный элемент
    if (lf)
    {
        // если у него был родитель
        if (lf->_parent)
        {
            // ищем у родителя, кем был этот элемент, и вместо него ставим бублик
            if (lf->_parent->_left == lf)
                lf->_parent->_left = nullptr;
            else                                    // доп. не проверяем, что он был правым, иначе нарушение целостности
                lf->_parent->_right = nullptr;
        }

        // задаем нового родителя
        lf->_parent = this;
    }

    // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
    Node* prevLeft = _left;
    _left = lf;

    if (prevLeft)
        prevLeft->_parent = nullptr;

    return prevLeft;
}


template<typename Element, typename Compar>
typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::Node::setRight(Node* rg)
{
    // предупреждаем повторное присвоение
    if (_right == rg)
        return nullptr;

    // если новый правый — действительный элемент
    if (rg)
    {
        // если у него был родитель
        if (rg->_parent)
        {
            // ищем у родителя, кем был этот элемент, и вместо него ставим бублик
            if (rg->_parent->_left == rg)
                rg->_parent->_left = nullptr;
            else                                    // доп. не проверяем, что он был правым, иначе нарушение целостности
                rg->_parent->_right = nullptr;
        }

        // задаем нового родителя
        rg->_parent = this;
    }

    // если у текущего уже был один правый
    // — отменяем его родительскую связь и вернем его
    Node* prevRight = _right;
    _right = rg;

    if (prevRight)
        prevRight->_parent = nullptr;

    return prevRight;
}


//==============================================================================
// class RBTree
//==============================================================================

template<typename Element, typename Compar>
RBTree<Element, Compar>::RBTree()
{
    _root = nullptr;
    _dumper = nullptr;
}

template<typename Element, typename Compar>
RBTree<Element, Compar>::~RBTree()
{
    // грохаем пока что всех через корень
    if (_root)
        delete _root;
}


template<typename Element, typename Compar>
void RBTree<Element, Compar>::deleteNode(Node* nd)
{
    // если переданный узел не существует, просто ничего не делаем, т.к. в вызывающем проверок нет
    if (nd == nullptr)
        return;

    // потомков убьет в деструкторе
    delete nd;
}


template<typename Element, typename Compar>
void RBTree<Element, Compar>::insert(const Element &key)
{
    // этот метод можно оставить студентам целиком
    Node* newNode = insertNewBstEl(key);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_BST_INS, this, newNode);

    rebalance(newNode);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_INSERT, this, newNode);

}


template<typename Element, typename Compar>
const typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::find(const Element &key)
{
    Node* node = this->_root;

    //go down compare keys
    while (node)
    {
        if (key == node->_key)
            return node;

        //go down
        if (key < node->_key)
            node = node->_left;
        else
            node = node->_right;
    }

    //in case when node with that key wasn't find
    return nullptr;
}

template<typename Element, typename Compar>
typename RBTree<Element, Compar>::Node*
RBTree<Element, Compar>::insertNewBstEl(const Element &key)
{
    if (find(key) != nullptr)
        throw std::invalid_argument("Node with this key already exist");

    Node* insertNode = new Node(key, nullptr, nullptr, nullptr, RED);
    Node* node = this->_root; // for iteration
    Node* parent = nullptr;

    while (node)
    {
        //remember parent
        parent = node;

        //go down
        if (key < node->_key)
            node = node->_left;
        else
            node = node->_right;
    }


    if (!parent) //if tree is empty set root
        this->_root = insertNode;
    else
    {
        //set child for parent
        if (parent->_key < key)
            parent->_right = insertNode;
        else
            parent->_left = insertNode;

    }

    //set parent for child
    insertNode->_parent = parent;

    return insertNode;
}


template<typename Element, typename Compar>
typename RBTree<Element, Compar>::Node*
RBTree<Element, Compar>::rebalanceDUG(Node* nd)
{
    Node* grandpa = (Node*) nd->getParent()->getParent();
    Node* dad = (Node*) nd->getParent();
    bool isLeft = dad->isLeftChild();

    // если зашли в этот метод, значит есть батя и дед


    /// левый/правый
    Node* uncle = grandpa->_right; // для левого случая нужен правый дядя и наоборот.
    if (!isLeft)
        uncle = grandpa->_left; // для левого случая нужен правый дядя и наоборот.

    // если дядя такой же красный, как сам нод и его папа...
    if (uncle && uncle->isRed())
    {
        // дядю и папу красим в черное
        uncle->setBlack();
        dad->setBlack();

        // а дедушку — в коммунистические цвета
        grandpa->setRed();

        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR1, this, nd);

        // теперь чередование цветов "узел-папа-дедушка-дядя" — К-Ч-К-Ч, но надо разобраться, что там
        // с дедушкой и его предками, поэтому продолжим с дедушкой
        nd = grandpa;

        return nd;
    }

    /// левый/правый
    // дядя черный
    if (isLeft)
    {
        // смотрим, является ли узел "правильно-правым" у папочки
        if (nd->isRightChild())                                        // для левого случая нужен правый узел
        {                                               // CASE2 в действии
            nd = dad;
            rotLeft(nd);
        }
    } else
    {
        // смотрим, является ли узел "правильно-левым" у папочки
        if (nd->isLeftChild())                                          // для правого случая нужен правый узел,
        {                                               // CASE2 в действии
            nd = dad;
            rotRight(nd);
        }
    }


    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR3D, this, nd);

    // CASE3 в действии

    nd->_parent->setBlack();
    nd->_parent->_parent->setRed();

    /// левый/правый
    if (isLeft)
        rotRight(nd->_parent->_parent);
    else
        rotLeft(nd->_parent->_parent);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR3G, this, nd);


    return nd;
}


template<typename Element, typename Compar>
void RBTree<Element, Compar>::rebalance(Node* nd)
{

    // пока папа есть и он цвета пионерского галстука, действуем
    while (nd->isDaddyRed())
        nd = rebalanceDUG(
                nd);                                              // локальная перебалансировка семейства "папа, дядя, дедушка" и повторная проверка

    // case 0 (add root)
    this->_root->_color = BLACK;
}


template<typename Element, typename Compar>
void RBTree<Element, Compar>::rotLeft(typename RBTree<Element, Compar>::Node* nd)
{
    // TODO: метод реализуют студенты


    Node* y = nd->_right;

    if (!y)
        throw std::invalid_argument("Can't rotate right since the left child is nil");

    //
    nd->setRight(y->_left);

    //ставим дедушке нового потомка
    if (nd->getParent())
        if (nd->isLeftChild())
            nd->_parent->setLeft(y);
        else
            nd->_parent->setRight(y);
    else
        this->_root = y;

    y->setLeft(nd);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_LROT, this, nd);
}


template<typename Element, typename Compar>
void RBTree<Element, Compar>::rotRight(typename RBTree<Element, Compar>::Node* nd)
{

    // левый потомок, который станет после правого поворота "выше"

    Node* y = nd->_left;

    if (!y)
        throw std::invalid_argument("Can't rotate right since the left child is nil");

    //
    nd->setLeft(y->_right);

    //ставим дедушке нового потомка
    if (nd->getParent())
        if (nd->isLeftChild())
            nd->_parent->setLeft(y);
        else
            nd->_parent->setRight(y);
    else
        this->_root = y;

    y->setRight(nd);

    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RROT, this, nd);
}


} // namespace xi

