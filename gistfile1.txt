# Build with
#   CXX=c++ python3 setup.py build develop

import setuptools
import sys

from torch.utils import cpp_extension

extra_compile_args = []
extra_link_args = []

if sys.platform == 'darwin':
    extra_compile_args += ['-stdlib=libc++', '-mmacosx-version-min=10.12']
    extra_link_args += ['-stdlib=libc++']


tensorbug = cpp_extension.CppExtension(
    name='tensorbug',
    sources=['bug.cc'],
    language='c++',
    extra_compile_args=['-std=c++17'] + extra_compile_args,
    extra_link_args=extra_link_args,
)


setuptools.setup(
    name='tensorbug',
    ext_modules=[tensorbug],
    cmdclass={'build_ext': cpp_extension.BuildExtension})
