/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-10T02:12:35+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-10T02:21:38+08:00
* @Inc: Google, FB
* @Difficulty: Hard
*/


/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:
1. Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
2. According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
*/

// 类似并查集的方法
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> union(n, 0);
        iota(union.begin(), union.end(), 0);
        for(auto i:edges) {
            
        }
    }
};
