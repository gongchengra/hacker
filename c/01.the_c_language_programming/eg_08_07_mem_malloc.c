/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_08_07_mem_malloc.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-25
* Last Modified : 2020-04-25 15:22:43+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long Align;
typedef union header
{
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x; // force alignment
} Header;
Header base, *freep = NULL;
#define NALLOC 1024
void free(void *ap) {
    Header *bp, *p;
    bp = (Header *)ap -1;
    for(p=freep;!(bp>p && bp < p->s.ptr);p=p->s.ptr){
        if(p>=p->s.ptr && (bp>p||bp<p->s.ptr)){
            break;
        }
    }
    if(bp+bp->s.size == p->s.ptr){
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else {
        bp->s.ptr = p->s.ptr;
    }
    if(p + p->s.size == bp){
        p->s.size +=bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else {
        p->s.ptr = bp;
    }
    freep = p;
}
Header *moremem(unsigned nu) {
    char *cp, *sbrk(int);
    Header *up;
    if(nu < NALLOC) {
        nu = NALLOC;
    }
    cp = sbrk(nu*sizeof(Header));
    if(cp == (char *)-1) {
        return NULL;
    }
    up = (Header *)cp;
    up->s.size = nu;
    free((void *)(up+1));
    return freep;
}
void *mallockr(unsigned nbytes) {
    Header *p, *prevp;
    unsigned nunits;
    nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
    if((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for(p=prevp->s.ptr;;prevp= p, p=p->s.ptr) {
        if(p->s.size > nunits) {
            if(p->s.size == nunits) {
                prevp->s.ptr = p->s.ptr;
            }else{
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p+1);
        }
        if(p==freep){
            if((p=moremem(nunits))==NULL) {
                return NULL;
            }
        }
    }
}
int main(int argc, char **argv){
    char *str;
    str = (char *)mallockr(1);
    strcpy(str, "laogongshuo.com");
    printf("String = %s,  Address = %c\n", str, *str);
    printf("String = %s,  Address = %c\n", str, *(str + 1));
    printf("%lu\n", strlen(str));
    printf("%ld\n", sizeof(Header));
    free(str);
    return 0;
}

