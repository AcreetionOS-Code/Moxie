# meson subbuild for xlibre shim (simple test)

xlibre_shim_sources = ['xlibre-shim.c']

# Build a simple test executable by compiling shim + test together so it
# doesn't require adding a library target elsewhere yet.
test_sources = ['xlibre-shim.c', 'test-xlibre-shim.c']

xcb_dep = dependency('xcb', required: false)

if xcb_dep.found()
  test_exe = executable('test-xlibre-shim', test_sources, dependencies: xcb_dep, install: false, c_args: ['-DHAVE_XCB'])
else
  test_exe = executable('test-xlibre-shim', test_sources, install: false)
endif

test('xlibre-shim', test_exe)
