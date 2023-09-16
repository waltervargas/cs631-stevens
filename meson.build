project(
  'cs631',
  'c',
  default_options: ['warning_level=3']
)

# dnsproxy program
fds_src_02 = [
  'src/fds_max.c',
]
fds_02_exec = executable('fds_02', fds_src_02)

# tests
check_dep = dependency('check')

# Include tests if check_dep dependency is found
if check_dep.found()
  fds_02_test_src = [
    'src/fds_02_test.c',
  ]
  fds_02_test_exec = executable(
    'fds_02_test',
    fds_02_test_src,
    dependencies: [check_dep]
  )
  test('fds_02_test', fds_02_test_exec)
endif
