#include "chplrt.h"
#include "chplthreads.h"
#include "chplmem.h"
#include "error.h"
#include <stdint.h>

// Mutex

int _chpl_mutex_lock(_chpl_mutex_p mutex) { return 0; }
void _chpl_mutex_unlock(_chpl_mutex_p mutex) { }


// Sync variables

int _chpl_sync_lock(_chpl_sync_aux_t *s) { return s == NULL; }
void _chpl_sync_unlock(_chpl_sync_aux_t *s) { }

int _chpl_sync_wait_full_and_lock(_chpl_sync_aux_t *s, int32_t lineno, _string filename) {
  if (*s)
    return 0;
  else {
    _chpl_error("sync var empty (running in single-threaded mode)", lineno, filename);
    return 1;
  }
}

int _chpl_sync_wait_empty_and_lock(_chpl_sync_aux_t *s, int32_t lineno, _string filename) {
  if (*s) {
    _chpl_error("sync var full (running in single-threaded mode)", lineno, filename);
    return 1;
  }
  else return 0;
}

void _chpl_sync_mark_and_signal_full(_chpl_sync_aux_t *s) {
  *s = true;
}

void _chpl_sync_mark_and_signal_empty(_chpl_sync_aux_t *s) {
  *s = false;
}

_chpl_bool _chpl_sync_is_full(void *val_ptr, _chpl_sync_aux_t *s, _chpl_bool simple_sync_var) {
  return *s;
}

void _chpl_init_sync_aux(_chpl_sync_aux_t *s) {
  *s = false;
}


// Single variables

int _chpl_single_lock(_chpl_single_aux_t *s) { return s == NULL; }

int _chpl_single_wait_full(_chpl_single_aux_t *s, int32_t lineno, _string filename) {
  if (*s)
    return 0;
  else {
    _chpl_error("single var empty (running in single-threaded mode)", lineno, filename);
    return 1;
  }
}

void _chpl_single_mark_and_signal_full(_chpl_single_aux_t *s) {
  *s = true;
}

_chpl_bool _chpl_single_is_full(void *val_ptr, _chpl_single_aux_t *s, _chpl_bool simple_single_var) {
  return *s;
}

void _chpl_init_single_aux(_chpl_single_aux_t *s) {
  *s = false;
}


// Threads

int32_t _chpl_threads_getMaxThreads(void) { return 1; }
int32_t _chpl_threads_maxThreadsLimit(void) { return 1; }

void initChplThreads() { }
void exitChplThreads() { }
void _chpl_thread_init(void) { }

uint64_t _chpl_thread_id(void) { return 0; }
_chpl_bool _chpl_get_serial(void) { return true; }
void _chpl_set_serial(_chpl_bool state) {
  if (!state)
    _chpl_error("cannot set serial state to false when running in single-threaded mode", 0, 0);
}

int
_chpl_begin(_chpl_threadfp_t fp, _chpl_threadarg_t a, _Bool serial_state) {
  (*fp)(a);
  return 0;
}
