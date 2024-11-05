class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function addTwoNumbers(
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null {
  let result: ListNode = new ListNode(0, null);
  let dummy = result;
  let carry: number = 0;
  while (l1 != null && l2 != null) {
    const sum = l1.val + l2.val + carry;
    dummy.next = new ListNode(sum % 10, null);
    dummy = dummy.next;
    carry = sum >= 10 ? 1 : 0;
    l1 = l1.next;
    l2 = l2.next;
  }
  while (l1 != null) {
    const sum = l1.val + carry;
    dummy.next = new ListNode(sum % 10, null);
    dummy = dummy.next;
    carry = sum >= 10 ? 1 : 0;
    l1 = l1.next;
  }
  while (l2 != null) {
    const sum = l2.val + carry;
    dummy.next = new ListNode(sum % 10, null);
    dummy = dummy.next;
    carry = sum >= 10 ? 1 : 0;
    l2 = l2.next;
  }
  if (carry != 0) {
    dummy.next = new ListNode(1, null);
  }
  return result.next;
}
