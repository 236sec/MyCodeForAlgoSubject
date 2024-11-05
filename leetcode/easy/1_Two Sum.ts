function twoSum(nums: number[], target: number): number[] {
  const myHash: { [key: number]: number } = {};
  for (let i = 0; i < nums.length; i++) {
    myHash[target - nums[i]] = i;
  }
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] in myHash && i != myHash[nums[i]]) {
      return [i, myHash[nums[i]]];
    }
  }
  return [];
}
