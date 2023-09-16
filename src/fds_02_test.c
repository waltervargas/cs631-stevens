#include <check.h>
#include <stdlib.h>
#include <check.h>
#include <unistd.h>
#include <stdio.h>

#define SUITE "fds_02"

START_TEST(test_fd_constants)
{
    ck_assert_int_eq(0, STDIN_FILENO);
    ck_assert_int_eq(1, STDOUT_FILENO);
    ck_assert_int_eq(2, STDERR_FILENO);
}

/*
The variables stdin, stdout, and stderr are of type FILE *, which are pointers to
a FILE structure, not integers.

The file descriptor (FD), however, is an integer that the operating system uses
as an index into a table of open files.

You can obtain the file descriptor associated with a FILE * stream using the
fileno() function defined in <stdio.h>.

Some Concepts to Ponder:

  - Streams vs File Descriptors: A stream provides a high level interface for
    I/O in C that's part of the C standard lib.

  - File descriptors are low-level construct more close tied to the Unix OS.

  - Functions like read(2) and write(2) use file descriptors, while fread(3) and
    fwrite(3) use FILE* streams.

  - FILE* structure encapsulates more information than just the file descriptor,
    like buffers, flags, etc. This allows for more optimized and flexible IO
    operations.

  - Portability: FILE* streams are portable. Since they are part of the C
    stdlib, code using FILE* is often more portable than code using file
    descriptors directly. However, you may lose some control and specificty that
    comes with using FDs.

  - Scare Resources: File descriptors are a limited resource provided by the
    operating system. Always close any unused file descriptors to prevent
    resource leaks, or starvation, even though FILE* streams usually handle this
    automatically when you close the stream.
*/
START_TEST(test_fd_streams)
{
    ck_assert_int_eq(0, fileno(stdin));
    ck_assert_int_eq(1, fileno(stdout));
    ck_assert_int_eq(2, fileno(stderr));
}

Suite* suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create(SUITE);
    tc = tcase_create(SUITE);

    tcase_add_test(tc, test_fd_constants);
    tcase_add_test(tc, test_fd_streams);
    suite_add_tcase(s, tc);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    setenv("CK_COLOR_ALWAYS", "yes", 1);
    s = suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_SUBUNIT);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
