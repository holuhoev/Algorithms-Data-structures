#include <cstdlib>

//=============================================================================
//== NodeSkipList =============================================================
//=============================================================================

template<class Value, class Key, int numLevels>
void NodeSkipList<Value, Key, numLevels>::clear(void)
{
    for (int i = 0; i < numLevels; ++i)
    {
        this->m_nextjump[i] = 0;
    }
    this->m_levelHighest = -1;
}

template<class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(void)
{
    clear();
}

template<class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(Key key)
{
    clear();

    this->m_key = key;
}

template<class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(Key key, Value value)
{
    clear();

    this->m_key = key;
    this->m_value = value;
}
//=============================================================================
//== End of: NodeSkipList =====================================================
//=============================================================================

//=============================================================================
//== SkipList =================================================================
//=============================================================================
template<class Value, class Key, int numLevels>
SkipList<Value, Key, numLevels>::SkipList(double probability)
{
    m_probability = probability;
    for (int i = 0; i < numLevels; ++i)
    {
        // Lets use m_pPreHead as a final sentinel element
        this->m_pPreHead->m_nextjump[i] = this->m_pPreHead;
    }

    this->m_pPreHead->m_levelHighest = numLevels - 1;
}

template<class Value, class Key, int numLevels>
void SkipList<Value, Key, numLevels>::insert(Value value, Key key)
{
    TypeNode* run = findLastLessThan(key);


    //insert in dense level
    TypeNode* next = run->m_next;
    TypeNode* node = new TypeNode;

    //initialize
    node->m_key = key;
    node->m_value = value;

    run->m_next = node;
    node->m_next = next;

    double prob = (double) rand() / RAND_MAX;
    int i = 0; // level

    while (prob < m_probability && i < numLevels)
    {
        //find nodeBefore in current level
        if (i > run->m_levelHighest)
        {
            run = this->m_pPreHead;
            int j = numLevels - 1;// current level

            //go down from top
            while (j >= i)
            {
                if (run->m_nextjump[j] != this->m_pPreHead && run->m_nextjump[j]->m_key < key)
                {
                    run = run->m_nextjump[j];

                } else
                    j--;
            }
        }

        next = run->m_nextjump[i];

        node->m_levelHighest++;

        run->m_nextjump[i] = node;
        node->m_nextjump[i++] = next;

        prob = (double) rand() / RAND_MAX;
    }


}

template<class Value, class Key, int numLevels>
typename SkipList<Value, Key, numLevels>::TypeNode* SkipList<Value, Key, numLevels>::findFirst(Key key) const
{
    TypeNode* run = this->m_pPreHead;
    int i = numLevels - 1;// current level

    //go down from top
    while (i >= 0)
    {
        if (run->m_nextjump[i] != this->m_pPreHead && run->m_nextjump[i]->m_key <= key)
        {
            run = run->m_nextjump[i];

            //if find
            if (run->m_key == key)
                return run;
        } else
            i--;
    }

    //if find key in the lowest level
    while (run->m_next != this->m_pPreHead)
    {
        run = run->m_next;

        if (run->m_key == key)
            return run;
    }

    //if element is not found
    return nullptr;

}

template<class Value, class Key, int numLevels>
typename SkipList<Value, Key, numLevels>::TypeNode* SkipList<Value, Key, numLevels>::findLastLessThan(Key key) const
{
    TypeNode* run = this->m_pPreHead;
    int i = numLevels - 1;// current level

    while (i >= 0)
    {
        if (run->m_nextjump[i] != this->m_pPreHead && run->m_nextjump[i]->m_key < key)
        {
            run = run->m_nextjump[i];
        } else
            i--;
    }

    while (run->m_next != this->m_pPreHead && run->m_next->m_key < key)
    {
        run = run->m_next;
    }

    return run;

}

template<class Value, class Key, int numLevels>
void SkipList<Value, Key, numLevels>::remove(TypeNode* node)
{
    //in order to except spending time
    if(!node)
        throw std::invalid_argument("Null");

    TypeNode* find = findFirst(node->m_key);
    if(!find)
        throw std::invalid_argument("Node isn't in list");

    bool isRemove = false;
    int i = numLevels - 1;// current level
    TypeNode* prevNodeOnLevel = this->m_pPreHead;
    int level = 0;

    while (i >= 0)
    {
        //go down
        if(prevNodeOnLevel->m_nextjump[i] == this->m_pPreHead || node->m_key < prevNodeOnLevel->m_nextjump[i]->m_key)
        {
            --i;
            continue;
        }

        if(prevNodeOnLevel->m_nextjump[i] == node )
        {
            //connect prev to next
            prevNodeOnLevel->m_nextjump[i] = node->m_nextjump[i];
            --i;
        }
        else //go right
            prevNodeOnLevel = prevNodeOnLevel->m_nextjump[i];

    }

    //go through dense level
    while (prevNodeOnLevel->m_next != this->m_pPreHead){
        if(prevNodeOnLevel->m_next != node )
        {
            prevNodeOnLevel = prevNodeOnLevel->m_next;
            continue;
        }

        isRemove = true;
        prevNodeOnLevel->m_next = node->m_next;
        delete node;
    }

    if(!isRemove)
        throw std::invalid_argument("Node isn't in list");
}
//=============================================================================
//== End of: SkipList =========================================================
//=============================================================================
