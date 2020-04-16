project('cpp20_simple_statistical_functions', 
        'cpp',
        version: '0.1.0',
        default_options: ['cpp_std=c++2a'])

includes = include_directories('.',)

src = files('main.cpp',) # , 'src/another.cpp', 'src/and_another.cpp')

exe = executable('simple_statistical_functions_test',
                 sources: src,
                 include_directories: includes) 


# https://mesonbuild.com/Unit-tests.html
tort_exe = executable('tort', sources: './testing/test_of_ranges_test.cpp')
test('test if range work', tort_exe)

