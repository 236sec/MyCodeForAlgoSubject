# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bst(self,nums: List[int],i: int,j: int) -> Optional[TreeNode]:
        if i > j:
            return None
        mid = (i+j) // 2
        mtree = TreeNode(nums[mid])
        ltree = self.bst(nums,i,mid-1)
        rtree = self.bst(nums,mid+1,j)
        mtree.left = ltree
        mtree.right = rtree
        return mtree
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums) == 0:
            return None
        return self.bst(nums,0,len(nums)-1)