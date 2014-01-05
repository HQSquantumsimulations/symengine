#include <iostream>

#include "ntheory.h"
#include "integer.h"

using CSymPy::Integer;
using CSymPy::print_stack_on_segfault;
using CSymPy::rcp;
using CSymPy::RCP;
using CSymPy::integer;

void test_gcd_lcm()
{
    RCP<Integer> i2 = integer(2);
    RCP<Integer> i3 = integer(3);
    RCP<Integer> i4 = integer(4);
    RCP<Integer> i6 = integer(6);

    assert(eq(gcd(*i2, *i4), integer(2)));
    assert(eq(gcd(*i2, *i3), integer(1)));
    assert(eq(gcd(*i2, *i6), integer(2)));
    assert(eq(gcd(*i3, *i6), integer(3)));

    assert(eq(lcm(*i2, *i4), integer(4)));
    assert(eq(lcm(*i2, *i3), integer(6)));
    assert(eq(lcm(*i2, *i6), integer(6)));
    assert(eq(lcm(*i3, *i6), integer(6)));
}

void test_nextprime()
{
    RCP<Integer> i1 = integer(1);
    RCP<Integer> i5 = integer(5);
    RCP<Integer> i6 = integer(6);

    assert(eq(nextprime(*i1), integer(2)));
    assert(eq(nextprime(*i5), integer(7)));
    assert(eq(nextprime(*i6), integer(7)));
}

void test_probab_prime_p()
{
    RCP<Integer> i1 = integer(1);
    RCP<Integer> i5 = integer(5);
    RCP<Integer> i6 = integer(6);

    assert(probab_prime_p(*i1) == 0);
    assert(probab_prime_p(*i5) == 2);
    assert(probab_prime_p(*i6) == 0);
}

int main(int argc, char* argv[])
{
    print_stack_on_segfault();

    test_gcd_lcm();
    test_nextprime();
    test_probab_prime_p();

    return 0;
}
