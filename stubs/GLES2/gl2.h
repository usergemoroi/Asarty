#ifndef GLES2_GL2_H
#define GLES2_GL2_H
#include <stdint.h>
typedef float GLfloat;
typedef int GLint;
typedef unsigned int GLuint;
typedef unsigned int GLenum;
typedef int GLsizei;
typedef unsigned char GLboolean;
typedef signed char GLbyte;
typedef short GLshort;
typedef unsigned short GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLbitfield;
typedef float GLclampf;
typedef void GLvoid;
typedef intptr_t GLsizeiptr;
typedef intptr_t GLintptr;

#define GL_FALSE 0
#define GL_TRUE 1
#define GL_VERSION 0x1F02
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_MAX_TEXTURE_SIZE 0x0D33

#ifdef __cplusplus
extern "C" {
#endif
const uint8_t* glGetString(GLenum name);
void glGetIntegerv(GLenum name, GLint* data);
#ifdef __cplusplus
}
#endif

// Add dummy imgl3w
#define imgl3wInit() 0
#define imgl3wShutdown() 
#endif
