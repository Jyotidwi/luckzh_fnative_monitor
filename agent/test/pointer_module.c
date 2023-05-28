#include <stddef.h>
#include <stdint.h>

typedef size_t gsize;
typedef void * gpointer;
typedef uint32_t guint32;
typedef char gchar;

typedef struct _GumSoinfo GumSoinfo;

struct _GumSoinfo
{


  gpointer phdr;
  gsize phnum;

  gpointer base;
  gsize size;



  gpointer dynamic;



  gpointer next;

  uint32_t flags;

  const gchar * strtab;
  gpointer symtab;

  gsize nbucket;
  gsize nchain;
  guint32 * bucket;
  guint32 * chain;



  gpointer plt_relx;
  gsize plt_relx_count;

  gpointer relx;
  gsize relx_count;

  gpointer * preinit_array;
  gsize preinit_array_count;

  gpointer * init_array;
  gsize init_array_count;
  gpointer * fini_array;
  gsize fini_array_count;

  gpointer init_func;
  gpointer fini_func;
};

size_t get_init_array_offset(){
    return offsetof(GumSoinfo,init_array);
} 
size_t get_init_offset(){
    return offsetof(GumSoinfo,init_func);
} 
void* get_init_array(GumSoinfo* gsi){
    return gsi->init_array;
}
int get_init_array_count(GumSoinfo* gsi){
    return gsi->init_array_count;
}
void* get_init_func(GumSoinfo* gsi){
    return gsi->init_func;
}