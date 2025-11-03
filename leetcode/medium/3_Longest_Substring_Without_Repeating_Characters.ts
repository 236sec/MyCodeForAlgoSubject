function lengthOfLongestSubstring(s: string): number {
  let myhash: { [key: string]: number } = {};
  let result = 0;
  let count = 0;
  for (const char of s) {
    if (char in myhash) {
      count = 1;
      myhash = {};
      myhash[char] = 1;
    } else {
      myhash[char] = 1;
      count++;
    }
    result = count > result ? count : result;
  }
  return result;
}

lengthOfLongestSubstring("pwwkew");
