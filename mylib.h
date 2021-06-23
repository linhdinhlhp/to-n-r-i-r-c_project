#ifndef MYLIB_H_
#define MYLIB_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "cgraph/cgraph.h"
#include "mylib.c"

void prufer(cgraph_t g, cgraph_ivec_t prufer);
cgraph_t find_mst(cgraph_t g, cgraph_ivec_t weights);
cgraph_t reversegraph(cgraph_t g);
void print_fathercode(cgraph_t g);
void find_scc(cgraph_t g);
void print_dfs(cgraph_t g);
void print_kruskal(cgraph_t g, int parent[], cgraph_ivec_t weights);

#endif