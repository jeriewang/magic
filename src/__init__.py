from magicWrapper import (
    MAGIC_NONE,
    MAGIC_DEBUG,
    MAGIC_SYMLINK,
    MAGIC_COMPRESS,
    MAGIC_DEVICES,
    MAGIC_MIME_TYPE,
    MAGIC_MIME_ENCODING,
    MAGIC_MIME,
    MAGIC_CONTINUE,
    MAGIC_CHECK,
    MAGIC_PRESERVE_ATIME,
    MAGIC_RAW,
    MAGIC_ERROR,
    MAGIC_APPLE,
    MAGIC_EXTENSION,
    MAGIC_COMPRESS_TRANSP,
    MAGIC_NO_CHECK_APPTYPE,
    MAGIC_NO_CHECK_CDF,
    MAGIC_NO_CHECK_COMPRESS,
    MAGIC_NO_CHECK_ELF,
    MAGIC_NO_CHECK_ENCODING,
    MAGIC_NO_CHECK_SOFT,
    MAGIC_NO_CHECK_TAR,
    MAGIC_NO_CHECK_TEXT,
    MAGIC_NO_CHECK_TOKENS,
    MAGIC_NO_CHECK_JSON,
    MAGIC_NO_CHECK_CSV,
    check as _check, checkBuf as _checkBuf
)


def check(path: str, flags=MAGIC_CONTINUE | MAGIC_PRESERVE_ATIME):
    """
    :param path: Path to the file to check
    :param flags: The flags to use, default is MAGIC_CONTINUE | MAGIC_PRESERVE_ATIME. See libmagic(3) for details
    :return: the string information returned by the library. See libmagic(3) for details
    """
    _check(path,flags)

def checkBuf(buf:bytes, flags=MAGIC_CONTINUE | MAGIC_PRESERVE_ATIME):
    _checkBuf(buf,len(buf),flags)