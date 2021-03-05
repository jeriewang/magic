#include <pybind11/pybind11.h>

namespace py = pybind11;
extern "C" {
    #include "magicWrapper.h"
}

#define MAGIC_EXPORT(name) m.attr(#name)=name;

PYBIND11_MODULE(magicWrapper, m) {
    m.def("check", &check);
    m.def("checkBuf", &checkBuf);
    MAGIC_EXPORT(MAGIC_NONE)
    MAGIC_EXPORT(MAGIC_DEBUG)
    MAGIC_EXPORT(MAGIC_SYMLINK)
    MAGIC_EXPORT(MAGIC_COMPRESS)
    MAGIC_EXPORT(MAGIC_DEVICES)
    MAGIC_EXPORT(MAGIC_MIME_TYPE)
    MAGIC_EXPORT(MAGIC_MIME_ENCODING)
    MAGIC_EXPORT(MAGIC_MIME)
    MAGIC_EXPORT(MAGIC_CONTINUE)
    MAGIC_EXPORT(MAGIC_CHECK)
    MAGIC_EXPORT(MAGIC_PRESERVE_ATIME)
    MAGIC_EXPORT(MAGIC_RAW)
    MAGIC_EXPORT(MAGIC_ERROR)
    MAGIC_EXPORT(MAGIC_APPLE)
    MAGIC_EXPORT(MAGIC_EXTENSION)
    MAGIC_EXPORT(MAGIC_COMPRESS_TRANSP)
    MAGIC_EXPORT(MAGIC_NO_CHECK_APPTYPE)
    MAGIC_EXPORT(MAGIC_NO_CHECK_CDF)
    MAGIC_EXPORT(MAGIC_NO_CHECK_COMPRESS)
    MAGIC_EXPORT(MAGIC_NO_CHECK_ELF)
    MAGIC_EXPORT(MAGIC_NO_CHECK_ENCODING)
    MAGIC_EXPORT(MAGIC_NO_CHECK_SOFT)
    MAGIC_EXPORT(MAGIC_NO_CHECK_TAR)
    MAGIC_EXPORT(MAGIC_NO_CHECK_TEXT)
    MAGIC_EXPORT(MAGIC_NO_CHECK_TOKENS)
    MAGIC_EXPORT(MAGIC_NO_CHECK_JSON)
    MAGIC_EXPORT(MAGIC_NO_CHECK_CSV)
}