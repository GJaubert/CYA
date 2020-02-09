#include "sorted_vector_t.hpp"

#include <climits>
#include <iomanip>

namespace CyA
{

void sorted_vector_t::merge_sort(void)
{
    merge_sort(0, size() - 1);
}

void sorted_vector_t::write(ostream& os) const
{
    const int sz = size();

    os << "< ";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << "> ";
}


void sorted_vector_t::merge_sort(int l, int r)
{
    if (l < r) {
        
        int c = (l + r) / 2;

        merge_sort(l, c);

        merge_sort(c + 1, r);

        merge(l, c, r);
    }
}


////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v)
{
 v.clear();
 
 for(int i = l; i <= r; i++) {
   v.push_back(at(i));
 }
  v.push_back(10000); 
}

void sorted_vector_t::merge(int l, int c, int d)
{ 
 vector<int> v1;
 create_vector_sentinel(l,c,v1);

 vector<int> v2;
 create_vector_sentinel(c+1,d,v2);

 int max_sz = v1.size() + v2.size() -2;

 int ind_1 = 0;
 int ind_2 = 0;

 for(int i = 0; i < max_sz; i++) {
   if (v1[ind_1] < v2[ind_2]) {
     at(l+i) = v1[ind_1];
     ind_1++;
   }
   else {
     at(l+i) = v2[ind_2];
     ind_2++;
   }
 } 
}


////////////////////////////////////////////////////////////////////////////

}


ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v)
{
    v.write(os);
    return os;
}
