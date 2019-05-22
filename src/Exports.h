
#ifndef ZIP_EXPORT_H
#define ZIP_EXPORT_H

#ifdef ZIP_STATIC_DEFINE
#  define ZIP_EXPORT
#  define ZIP_NO_EXPORT
#else
#  ifndef ZIP_EXPORT
#    ifdef zip_EXPORTS
        /* We are building this library */
#      define ZIP_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ZIP_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ZIP_NO_EXPORT
#    define ZIP_NO_EXPORT 
#  endif
#endif

#ifndef ZIP_DEPRECATED
#  define ZIP_DEPRECATED __declspec(deprecated)
#endif

#ifndef ZIP_DEPRECATED_EXPORT
#  define ZIP_DEPRECATED_EXPORT ZIP_EXPORT ZIP_DEPRECATED
#endif

#ifndef ZIP_DEPRECATED_NO_EXPORT
#  define ZIP_DEPRECATED_NO_EXPORT ZIP_NO_EXPORT ZIP_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ZIP_NO_DEPRECATED
#    define ZIP_NO_DEPRECATED
#  endif
#endif

#endif /* ZIP_EXPORT_H */
