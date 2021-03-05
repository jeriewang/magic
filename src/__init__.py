from .magicWrapper import (
    NONE,
    DEBUG,
    SYMLINK,
    COMPRESS,
    DEVICES,
    MIME_TYPE,
    MIME_ENCODING,
    MIME,
    CONTINUE,
    CHECK,
    PRESERVE_ATIME,
    RAW,
    ERROR,
    APPLE,
    EXTENSION,
    COMPRESS_TRANSP,
    NO_CHECK_APPTYPE,
    NO_CHECK_CDF,
    NO_CHECK_COMPRESS,
    NO_CHECK_ELF,
    NO_CHECK_ENCODING,
    NO_CHECK_SOFT,
    NO_CHECK_TAR,
    NO_CHECK_TEXT,
    NO_CHECK_TOKENS,
    NO_CHECK_JSON,
    NO_CHECK_CSV,
    check as _check, checkBuf as _checkBuf
)
from typing import Union
from functools import reduce

def check(path: str, *flags) -> str:
    """
    :param path: Path to the file to check
    :param flags: The flags to use, default is PRESERVE_ATIME | RAW. See libmagic(3) for details. Note that MAGIC_RAW will be added for you.
    :return: the string information returned by the library. See libmagic(3) for details
    """
    if flags:
        l=list(flags)
        l.append(RAW)
        return _check(path,reduce(int.__or__,flags)).decode()
    else:
        return _check(path,RAW|PRESERVE_ATIME).decode()

def check_buf(buf:Union[str,bytes], *flags) -> str:
    """
    :param buf: the content
    :param flags: The flags to use, default is PRESERVE_ATIME | RAW. See libmagic(3) for details. Note that MAGIC_RAW will be added for you.
    :return: the string information returned by the library. See libmagic(3) for details
    """
    if flags:
        l=list(flags)
        l.append(RAW)
        return _checkBuf(buf,len(buf),reduce(int.__or__,l)).decode()
    else:
        return _checkBuf(buf,len(buf),RAW|PRESERVE_ATIME).decode()

