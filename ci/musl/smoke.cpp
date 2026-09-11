extern "C" {
#include <libqhull_r/qhull_ra.h>
}
#include <cstdio>
int main() {
  qhT context; qhT* qh=&context;
  coordT points[]={0,0,0, 1,0,0, 0,1,0, 0,0,1};
  char flags[]="qhull Qt";
  qh_zero(qh,stderr);
  int result=qh_new_qhull(qh,3,4,points,False,flags,nullptr,stderr);
  bool valid=result==0 && qh->num_vertices==4 && qh->num_facets==4;
  qh_freeqhull(qh,!qh_ALL);
  int current=0,total=0; qh_memfreeshort(qh,&current,&total);
  if (!valid || current || total) return 1;
  std::puts("PASS: Qhull tetrahedron convex hull");
}
