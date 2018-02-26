#include <stdio.h>
//#include <tchar.h>
#include <string>
#include <list>
#include <unordered_set>
#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class Block
{
public:
    Block() { }
    ~Block() { }

    std::string GetName() const { return m_name; } //made this a const function
    void SetName(std::string name) { m_name = name; }

    void AddAttribute(std::string attribute) { m_attributes.insert(attribute); }
    std::unordered_set<std::string> GetAttributes() { return m_attributes; }

private:
    std::string m_name;
    std::unordered_set<std::string> m_attributes;
};


///CUSTOM HASHER for unordered_set of Block*
struct BlockHasher
{
    size_t operator()(const Block *bptr) const
    {
        return std::hash<std::string>()(bptr->GetName());
    } 
};

///CUSTOM COMPARATOR for unordered_set of Block*
struct BlockComparator
{
    bool operator()(const Block *bptr1, const Block *bptr2) const
    {
        if(bptr1->GetName() == bptr2->GetName())
            return true;
        else
            return false;
    }
};


class Graph
{

public:

    // Adds the passed block to this graph. Potentially renames the block prior to insertion to guarantee
    // each block in the graph has a unique name.
    void AddBlock(Block* block)
    {
        // Make sure we have a unique name for this block within the content of this Graph object.
        std::string uniqueName = GetUniqueBlockNameInGraph(block);
        block->SetName(uniqueName);
        
        // Add it to our collection of blocks.
        m_blocks.insert(block);
    }

    

    std::list<Block*> GetBlocksWithAttribute(std::string attribute)
    {
        std::list<Block*> blocksWithAttribute;
        std::unordered_set<Block*,BlockHasher,BlockComparator>::iterator it = m_blocks.begin();
        while(it != m_blocks.end())
        {
            Block *bptr = *it;
            if (bptr->GetAttributes().find(attribute) != bptr->GetAttributes().end())
                blocksWithAttribute.push_front(bptr);

            it++;
        }
        return blocksWithAttribute;
    }

private:

    // // Determines if the specified blockName is already the name of a block in this Graph.
    // bool BlockNameExistsInGraph(std::string blockName)
    // {
    //     bool exists = false;
    //     for (auto i = m_blocks.begin(); i != m_blocks.end(); i++)
    //     {
    //         Block* iterBlock = *i;
    //         std::string iterName = iterBlock->GetName();
    //         if (iterName == blockName)
    //         {
    //             exists = true;
    //         }
    //     }

    //     return exists;
    // }

    // Generate a unique name for this block within the graph.
    // If there's no name collision, then the original Block name is returned.
    // If there is a name collision, then we will appends numbers to the name to make unique.
    // So if you call with a block named "a" and there's already a block named "a", then it will return "a1".
    // If there's already an "a1" then it will return "a2", and so on.
    std::string GetUniqueBlockNameInGraph(Block* block)
    {
        std::string originalName = block->GetName();
        std::string potentialName = block->GetName();
        unsigned int count = 0;
        Block tempBlock;
        
        bool foundUniqueName = false;
        while (foundUniqueName == false)
        {
            if (m_blocks.find(&tempBlock) == m_blocks.end())
            {
                foundUniqueName = true;
            }
            else  //Don't need the redundant call/check here again
            {
                std::ostringstream s;
                s << originalName << count;
                potentialName = s.str();
                tempBlock.SetName(potentialName);
                count++;
            }
        }

        return potentialName;
    }

private:

    // Here is our collection of blocks in this graph.
    // Changed this data structure from a List to an unordered_set
    std::unordered_set<Block*,BlockHasher,BlockComparator> m_blocks;
};




/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// DO NOT MODIFY ANY CODE BELOW THIS POINT
/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

static const int s_blockQuantity = 500;
static const int s_attributesPerBlock = 100;
static std::string s_blockBaseName("a");

std::vector<std::vector<std::string>> GetAttributeData()
{
    std::vector<std::vector<std::string>> attrData;

    for (int i = 0; i < s_blockQuantity; ++i)
    {
        std::vector<std::string> blockAttr;

        for (int j = 0; j < s_attributesPerBlock; j++)
        {
            std::ostringstream s;
            s << "attribute_" << j + i;
            blockAttr.push_back(s.str());
        }

        attrData.push_back(blockAttr);
    }

    return attrData;
}

std::chrono::milliseconds Measure_AddBlocks(Graph& graph)
{
    auto attrData = GetAttributeData();
    
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < s_blockQuantity; ++i)
    {
        Block* b = new Block;
        b->SetName(s_blockBaseName);
        for (auto a: attrData[i])
        {
            b->AddAttribute(a);
        }
        graph.AddBlock(b);
    }
    auto end = std::chrono::system_clock::now();

    // Post-measurement verification
    

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

std::chrono::milliseconds Measure_FindBlocksByAttribute(Graph& graph)
{
    auto start = std::chrono::system_clock::now();
    for (int j = 0; j < s_blockQuantity * 2; j++)
    {
        std::ostringstream s;
        s << "attribute_" << j;
        graph.GetBlocksWithAttribute(s.str()).size();
    }
    auto end = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

int main()
{
    Graph graph;

    auto timeAddBlocks = Measure_AddBlocks(graph);
    std::cout << "Measure_AddBlocks took: " << timeAddBlocks.count() << "ms.\n";

    auto timeFindBocksByAttribute = Measure_FindBlocksByAttribute(graph);
    std::cout << "Measure_FindBlocksByAttribute took: " << timeFindBocksByAttribute.count() << "ms.\n";

    return 0;
}