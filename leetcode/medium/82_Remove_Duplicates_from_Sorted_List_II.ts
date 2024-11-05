function deleteDuplicates(head: ListNode | null): ListNode | null {
  if (head == null) {
    return null;
  }
  let num: number = head.val;
  head = head.next;
  let result: ListNode = new ListNode(0, null);
  let dummy = result;
  let dupstage = false;
  while (head != null) {
    if (num != head.val && !dupstage) {
      dummy.next = new ListNode(num, null);
      dummy = dummy.next;
      num = head.val;
    } else if (num != head.val) {
      dupstage = false;
      num = head.val;
    } else if (num == head.val) {
      dupstage = true;
    }
    head = head.next;
  }
  if (!dupstage) {
    dummy.next = new ListNode(num, null);
  }
  return result.next as ListNode;
}
