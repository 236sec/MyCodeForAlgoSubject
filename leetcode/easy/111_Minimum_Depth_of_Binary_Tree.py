# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaf(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return -1
        if root.left == None and root.right == None:
            return 1
        lheight = self.findLeaf(root.left)
        rheight = self.findLeaf(root.right)
        if lheight != -1 and rheight != -1:
            return 1 + min(lheight,rheight)
        if lheight != -1:
            return 1 + lheight
        return 1 + rheight
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        return self.findLeaf(root)