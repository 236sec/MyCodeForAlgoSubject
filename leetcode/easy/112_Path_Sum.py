# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaf(self, root: Optional[TreeNode],totalSum,targetSum) -> bool:
        if root == None:
            return False
        if root.left == None and root.right == None and totalSum + root.val == targetSum:
            return True
        l = self.findLeaf(root.left,totalSum+root.val,targetSum)
        r = self.findLeaf(root.right,totalSum+root.val,targetSum)
        return l or r 
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root == None:
            return False
        return self.findLeaf(root,0,targetSum)