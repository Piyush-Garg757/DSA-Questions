/*Vertical Order Traversal of a Binary Tree

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

Example 3:
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int x = p.second.first, y = p.second.second;
            m[x][y].insert(node->val);
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }
        vector<vector<int>> ans;
        for (auto i : m)
        {
            vector<int> v;
            for (auto w : i.second)
            {
                v.insert(v.end(), w.second.begin(), w.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};
/*Step 1 : Vertical Traversal hota kya hai?
Har node ko ek coordinate dete hain.
Root ko maan lo
      3
Root = (0,0)
Rule:
Left child -> (x-1, y+1)
Right child -> (x+1, y+1)
Example
        3
      /   \
     9     20
          /  \
         15   7
Coordinates
        3 (0,0)
9 (-1,1)
20 (1,1)
15 (0,2)
7 (2,2)
Diagram
x = -1      x=0       x=1      x=2
   9          3         20        7
              |
             15
Vertical order
[
 [9],
 [3,15],
 [20],
 [7]
]

Step 2 : Agar same vertical me do nodes aa jaye?
Example
        1
      /   \
     2     3
      \   /
       5 6
Coordinates
1  -> (0,0)
2 -> (-1,1)
3 -> (1,1)
5 -> (0,2)
6 -> (0,2)
Ab x = 0 pe
1
5
6
Lekin
5 aur 6 dono same position
(0,2)
Leetcode bolta hai
Agar
same column
same row
to smaller value pehle.
Output
1 5 6
Isliye multiset use hua.

Step 3 : Data Structure
Ye line sabse dangerous lagti hai
map<int, map<int, multiset<int>>> m;
Isko todte hain.
Outer map
map<
    column,
    ...
>
Matlab
x
Store karega.
Example
-2
-1
0
1
2
Automatically sorted.
Andar
map<int, multiset<int>>
Ye
row
store karega.
Matlab
y
Again sorted.
Aur
multiset<int>
Store karega node values.
Kyuki same
(x,y)
par multiple nodes aa sakte hain.
Sorted bhi rahenge.
Overall
Column
   |
   ---> Row
           |
           ---> Values(sorted)

Example
Suppose
Column 0
Row 0
3
Row 2
15
6
Memory me
m
0
 |
 +---0
 |    |
 |    {3}
 |
 +---2
      |
      {6,15}
Kyuki multiset sorted hai.

Step 4 : Queue
queue<pair<TreeNode*, pair<int,int>>> q;
Har queue element
(Node , (x,y))
Store karega.
Example
(3,(0,0))
(9,(-1,1))
(20,(1,1))
Initially
q
3 (0,0)
q.push({root,{0,0}});

Step 5 : BFS
while(!q.empty())
Har node nikalo.
auto p=q.front();
q.pop();
Suppose
3 (0,0)
nikla.

Step 6
TreeNode* node=p.first;
int x=p.second.first;
int y=p.second.second;
Ab
node=3
x=0
y=0

Step 7
m[x][y].insert(node->val);
Matlab
m[0][0].insert(3);
Memory
0
0
3

Step 8
Left child
if(node->left)
q.push({node->left,{x-1,y+1}});
Current
(0,0)
Left
(-1,1)
Right child
(x+1,y+1)
Current
(0,0)
Right
(1,1)
Queue
9 (-1,1)
20 (1,1)

Step 9
Next
9
Store
m[-1][1]
insert(9)
Next
20
Store
m[1][1]
insert(20)
Next
15
Store
m[0][2]
insert(15)
Finally map
-1
   1 -> {9}
0
   0 -> {3}
   2 -> {15}
1
   1 -> {20}
2
   2 -> {7}

Step 10 : Answer banana
for(auto i:m)
Ye
Column wise
-1
0
1
2
jayega.
vector<int> v;
Current column.
for(auto w:i.second)
Ye rows pe iterate karega.
0
1
2
3
Automatically sorted.
Ab
w.second
multiset hai.
Usme ho sakta hai
5
6
7
v.insert(
      v.end(),
      w.second.begin(),
      w.second.end()
);
Matlab
multiset ke saare values
vector me daal do.
Example Dry Run
Tree
        1
      /   \
     2     3
      \   /
       5 6
Coordinates
1
(0,0)
2
(-1,1)
3
(1,1)
5
(0,2)
6
(0,2)
Map
-1
1->{2}
0
0->{1}
2->{5,6}
1
1->{3}
Output
[
[2],
[1,5,6],
[3]
]
Perfect.

Time Complexity
Let N = number of nodes.
Har node ke liye:
queue operations: O(1)
map insert (column): O(log C)
inner map insert (row): O(log R)
multiset insert: O(log K)
Worst case me C, R, aur K sab O(N) ho sakte hain.
Isliye overall:
Time = O(N log N)

Answer banane ke time bhi total elements N hi process hote hain, jo isi complexity me absorb ho jaata hai.

Space Complexity
Queue: O(N) (worst case)
Maps + multisets: har node ek baar store hota hai → O(N)
Answer vector: O(N)
Total auxiliary space (excluding output): O(N)*/