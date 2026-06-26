# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkheight(self, root) -> int:
        if root == None:
            return 0
        lheight = self.checkheight(root.left)
        if lheight == -1:
            return -1
        rheight = self.checkheight(root.right)
        if rheight == -1:
            return -1
        if abs(lheight - rheight) >= 2:
            return -1
        return 1 + max(lheight,rheight)
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        height = self.checkheight(root)
        if height == -1:
            return False
        return True