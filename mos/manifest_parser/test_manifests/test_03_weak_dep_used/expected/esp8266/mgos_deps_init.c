/* This file is auto-generated by mos build, do not edit! */

#include <stdbool.h>
#include <stdio.h>

#include "common/cs_dbg.h"

#include "mgos_app.h"


extern bool mgos_mylib4_init(void);
extern bool mgos_mylib2_init(void);
extern bool mgos_mylib1_init(void);
extern bool mgos_mylib3_init(void);

static const struct lib_descr {
  const char *title;
  bool (*init)(void);
} descrs[] = {

    // "mylib4". deps: [ "core" ]
    {.title = "mylib4", .init = mgos_mylib4_init},

    // "mylib2". deps: [ "core" "mylib4" ]
    {.title = "mylib2", .init = mgos_mylib2_init},

    // "mylib1". deps: [ "core" "mylib2" ]
    {.title = "mylib1", .init = mgos_mylib1_init},

    // "mylib3". deps: [ "core" "mylib4" ]
    {.title = "mylib3", .init = mgos_mylib3_init},

};

bool mgos_deps_init(void) {
  size_t i;
  for (i = 0; i < sizeof(descrs) / sizeof(struct lib_descr); i++) {
    LOG(LL_DEBUG, ("init %s...", descrs[i].title));
    if (!descrs[i].init()) {
      LOG(LL_ERROR, ("%s init failed", descrs[i].title));
      return false;
    }
  }

  return true;
}
