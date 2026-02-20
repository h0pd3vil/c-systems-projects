#ifndef ERROR_H
#define ERROR_H

/*
 * Common status/error codes for data-structure modules.
 *
 * Convention:
 * - Functions that mutate state return ds_status_t.
 * - DS_OK (0) means success.
 * - Negative values indicate specific failures.
 */

typedef enum {
    DS_OK = 0,
    DS_ERR_NULL = -1,
    DS_ERR_OOM = -2,
    DS_ERR_BOUNDS = -3,
    DS_ERR_EMPTY = -4,
    DS_ERR_STATE = -5
} ds_status_t;

#endif /* ERROR_H */