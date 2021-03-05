# Magic

Magic is a simple Python wrapper for libmagic(3) with no extra dependencies

## Build 

```sh
git clone git@github.com:jeriewang/magic --recurse-submodules
cmake src
make
```
## Examples

```py
>>> magic.check("/bin/python")
'symbolic link to python3'

>>> magic.check("/bin/python",magic.SYMLINK)
'ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=a05d8d800af460d0cafeb45752d47a835e3f32c0, for GNU/Linux 4.4.0, stripped'

>>> magic.check("/bin/python",magic.MIME)
'inode/symlink; charset=binary'

>>> magic.check("/bin/python",magic.MIME,magic.SYMLINK)
'application/x-pie-executable; charset=binary'

>>> magic.check_buf("<!DOCType html>\n")
'HTML document, ASCII text'
```
