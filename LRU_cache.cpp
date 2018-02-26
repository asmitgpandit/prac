// Write an LRU cache
// It's a key-value store where it maintains N items and when the N+1th item is added,
// it expires the least recently used (inserted or accessed) item

#include<unordered_map>
#include <iostream>
using namespace std;


#define MAX_CACHE_SIZE 5

struct cache_item
{
  int data;
  int timestamp;
};


class LRU_cache
{
  
  unordered_map<int,void *> umap;
  static long timestamp;
  
  int get_least_recently_used_item_key();
  
  public:
  
  int size(){return umap.size();}
  long get_new_timestamp(){++timestamp; if (!timestamp) umap.clear(); return timestamp;};
  void insert(int key, int data);
  int get_data(int key);
  void dump();
  
  
};

long LRU_cache::timestamp;

int LRU_cache::get_least_recently_used_item_key()
{
  int smallest_ts = ((cache_item *)(umap.begin()->second))->timestamp;
  int smallest_ts_key = umap.begin()->first;
  //unordered_map<int,pair<int,int>>::iterator it = umap.begin();
  for(auto it = umap.begin(); it != umap.end(); it++)
  {
    cache_item *pitem  = (cache_item *)it->second;
    if (pitem->timestamp < smallest_ts)
    {
      smallest_ts = pitem->timestamp;
      smallest_ts_key = it->first;
    }
  }
  return smallest_ts_key; 
}

void LRU_cache::insert(int key, int data)
{
  //if key already exists in the cache
  if (umap.find(key) != umap.end())
  {
    cache_item *p = (cache_item *)umap[key];
    p->data = data;
    p->timestamp = get_new_timestamp();
  }
  
  if (umap.size() == MAX_CACHE_SIZE)
  {
    //erase the LRUsed item
    int key_to_delete = get_least_recently_used_item_key();
    umap.erase(key_to_delete);
  }
  
  cache_item *new_item = new cache_item;
  new_item->data = data;
  new_item->timestamp = get_new_timestamp();
  
  umap.insert(make_pair(key,(void *)new_item));
}

int LRU_cache::get_data(int key)
{
  if(umap.find(key) != umap.end())
  {
    cache_item *p  = (cache_item *)umap[key];
    p->timestamp = get_new_timestamp();
    return p->data;
  }
  else
    return -1;
}

void LRU_cache::dump()
{
  for(auto a = umap.begin(); a!=umap.end(); a++)
  {
    int key = a->first;
    cache_item *p = (cache_item *)a->second;
    cout<<key<<" : "<<p->data<<"\t["<<p->timestamp<<"]"<<endl;
    
  }
}


int main()
{
  LRU_cache myCache;
  myCache.insert(5,77);
  myCache.insert(10,11);
  myCache.insert(15,20);
  myCache.insert(20,7);
  myCache.insert(25,67);
  cout<<myCache.get_data(5)<<endl;
  myCache.insert(30,107);
  
  cout<<"after first 6 inserts"<<endl;
  myCache.dump();
  myCache.insert(35,90);
  myCache.insert(40,55);
  myCache.insert(45,62);
  
  cout<<endl<<"cache contents after rest of the inserts"<<endl;
  myCache.dump();
  
  return 0;
}