#include <pybind11/pybind11.h>

namespace py = pybind11;
extern "C" {
    #include "magicWrapper.h"
}

py::bytes pCheck(char *filename, int flags){
    const char * str=check(filename,flags);
    auto bytes=PyBytes_FromString(str);
    free((void *)str);
    return py::reinterpret_steal<py::bytes>(bytes);
}

py::bytes pCheckBuf(char *buf,size_t len, int flags){
    const char * str=checkBuf((void *)buf,len,flags);
    auto bytes=PyBytes_FromString(str);
    free((void *)str);
    return py::reinterpret_steal<py::bytes>(bytes);
}


#define MAGIC_EXPORT(name) m.attr(#name)=MAGIC_##name;

PYBIND11_MODULE(magicWrapper, m) {
    m.def("check", &pCheck);
    m.def("checkBuf", &pCheckBuf);
    MAGIC_EXPORT(NONE)
    MAGIC_EXPORT(DEBUG)
    MAGIC_EXPORT(SYMLINK)
    MAGIC_EXPORT(COMPRESS)
    MAGIC_EXPORT(DEVICES)
    MAGIC_EXPORT(MIME_TYPE)
    MAGIC_EXPORT(MIME_ENCODING)
    MAGIC_EXPORT(MIME)
    MAGIC_EXPORT(CONTINUE)
    MAGIC_EXPORT(CHECK)
    MAGIC_EXPORT(PRESERVE_ATIME)
    MAGIC_EXPORT(RAW)
    MAGIC_EXPORT(ERROR)
    MAGIC_EXPORT(APPLE)
    MAGIC_EXPORT(EXTENSION)
    MAGIC_EXPORT(COMPRESS_TRANSP)
    MAGIC_EXPORT(NO_CHECK_APPTYPE)
    MAGIC_EXPORT(NO_CHECK_CDF)
    MAGIC_EXPORT(NO_CHECK_COMPRESS)
    MAGIC_EXPORT(NO_CHECK_ELF)
    MAGIC_EXPORT(NO_CHECK_ENCODING)
    MAGIC_EXPORT(NO_CHECK_SOFT)
    MAGIC_EXPORT(NO_CHECK_TAR)
    MAGIC_EXPORT(NO_CHECK_TEXT)
    MAGIC_EXPORT(NO_CHECK_TOKENS)
    MAGIC_EXPORT(NO_CHECK_JSON)
    MAGIC_EXPORT(NO_CHECK_CSV)
}
