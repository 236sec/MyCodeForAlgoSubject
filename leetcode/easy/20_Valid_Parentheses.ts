function isValid(s: string): boolean {
  const myhash: { [key: string]: string } = { "(": ")", "{": "}", "[": "]" };
  const mystack: string[] = [];
  for (const char of s) {
    if (char in myhash) {
      mystack.push(char);
    } else {
      if (mystack.length === 0) {
        return false;
      }

      const tmp = mystack.pop() as string;
      if (char !== myhash[tmp]) {
        return false;
      }
    }
  }
  if (mystack.length !== 0) {
    return false;
  }
  return true;
}
