#include <stdio.h>
#include <limits.h>

void add_to_stack(unsigned long long*, unsigned short);
unsigned short peak_at_stack(unsigned long long*);
unsigned short pop_from_stack(unsigned long long*);

int main(void) {
  unsigned long long stack = 0;

  add_to_stack(&stack, 3);
  add_to_stack(&stack, 34);
  add_to_stack(&stack, 0);
  add_to_stack(&stack, 50);
  printf("%llu", stack);
  printf("\n%llx\n", stack);
  printf("\n%hu", pop_from_stack(&stack));
  printf("\n%hu", pop_from_stack(&stack));
  printf("\n%hu", peak_at_stack(&stack));
  printf("\n%hu", pop_from_stack(&stack));
  printf("\n%hu", pop_from_stack(&stack));
  return 0;
}

void add_to_stack(unsigned long long *stack, unsigned short number) {
  *stack = *stack * USHRT_MAX + number;
}

unsigned short peak_at_stack(unsigned long long *stack) {
  unsigned short value = *stack % USHRT_MAX;
  return value;
}

unsigned short pop_from_stack(unsigned long long *stack) {
  unsigned short value = peak_at_stack(stack);
  *stack = (*stack - value) / USHRT_MAX;
  return value;
}

