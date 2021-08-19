#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>orderedSet1;

int main()
{
    orderedSet s;
    s.insert(5);
    s.insert(2);
    s.insert(6);
    s.insert(4);
    s.insert(2);
    s.insert(7);

    ///K-th element in a set (counting from zero)
    cout<< *s.find_by_order(0) <<endl;
    cout<< *s.find_by_order(1) <<endl;

    ///Number of items strictly smaller than k
    cout<< s.order_of_key(5) <<endl;
    cout<<"------------------------------"<<endl;
    orderedSet1 s1;
    s1.insert(5);
    s1.insert(2);
    s1.insert(6);
    s1.insert(4);
    s1.insert(2);
    s1.insert(7);

    ///K-th element in a set (counting from zero)
    cout<< *s1.find_by_order(0) <<endl;
    cout<< *s1.find_by_order(1) <<endl;

    ///Number of items strictly greater than k
    cout<< s1.order_of_key(7) <<endl;

    return 0;
}
