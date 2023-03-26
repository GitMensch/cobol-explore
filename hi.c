/* Generated by           cobc 3.1.2.0 */
/* Generated from         hi.cbl */
/* Generated at           Mar 26 2023 04:22:35 */
/* GnuCOBOL build date    Sep 14 2021 19:23:38 */
/* GnuCOBOL package date  Dec 23 2020 12:04:58 UTC */
/* Compile command        cobc -x -Wall -C hi.cbl help.c */

#include <stdio.h>
#include <string.h>
#define  COB_KEYWORD_INLINE __inline
#include <libcob.h>

#define  COB_SOURCE_FILE		"hi.cbl"
#define  COB_PACKAGE_VERSION		"3.1.2"
#define  COB_PATCH_LEVEL		0
#define  COB_MODULE_FORMATTED_DATE	"Mar 26 2023 04:22:35"
#define  COB_MODULE_DATE		20230326
#define  COB_MODULE_TIME		42235

/* Global variables */
#include "hi.c.h"

/* Function prototypes */

static int		hi ();
static int		hi_ (const int);
static void		hi_module_init (cob_module *module);
int		greeet (cob_u8_t *);
static int		greeet_ (const int, cob_u8_t *);
static void		greeet_module_init (cob_module *module);

/* Main function */
int
main (int argc, char **argv)
{
  cob_init (argc, argv);
  cob_stop_run (hi ());
}

/* Functions */

/* PROGRAM-ID 'hi' */

/* ENTRY 'hi' */

static int
hi ()
{
  return hi_ (0);
}

static int
hi_ (const int entry)
{
  /* Program local variables */
  #include "hi.c.l1.h"

  /* Start of function code */

  /* CANCEL callback */
  if (unlikely(entry < 0)) {
  	if (entry == -10)
  		goto P_dump;
  	if (entry == -20)
  		goto P_clear_decimal;
  	goto P_cancel;
  }

  /* Check initialized, check module allocated, */
  /* set global pointer, */
  /* push module stack, save call parameter count */
  if (cob_module_global_enter (&module, &cob_glob_ptr, 0, entry, 0))
  	return -1;

  /* Set address of module parameter list */
  module->cob_procedure_params = cob_procedure_params;

  /* Set frame stack pointer */
  frame_ptr = frame_stack;
  frame_ptr->perform_through = 0;
  frame_ptr->return_address_ptr = &&P_cgerror;

  /* Initialize rest of program */
  if (unlikely(initialized == 0)) {
  	goto P_initialize;
  }
  P_ret_initialize:

  /* Increment module active */
  module->module_active++;

  /* Entry dispatch */
  goto l_2;

  /* PROCEDURE DIVISION */

  /* Line: 7         : Entry     hi                      : hi.cbl */
  l_2:;

  /* Line: 8         : DISPLAY            : hi.cbl */
  cob_display (0, 1, 1, &c_1);

  /* Line: 9         : CALL               : hi.cbl */
  cob_procedure_params[0] = &f_8;
  cob_glob_ptr->cob_call_params = 1;
  cob_glob_ptr->cob_stmt_exception = 0;
  if (unlikely((cob_glob_ptr->cob_exception_code & 0x0b00) == 0x0b00)) cob_glob_ptr->cob_exception_code = 0;
    if (unlikely(call_greet.funcvoid == NULL || cob_glob_ptr->cob_physical_cancel))
  {
    call_greet.funcvoid = cob_resolve_cobol ("greet", 0, 1);
  }
  b_2 = ((int (*)(cob_s32_t))call_greet.funcint) ((cob_s32_t)(cob_get_numdisp (b_8, 3)));

  /* Line: 10        : MOVE               : hi.cbl */
  memcpy (b_8, "004", 3);

  /* Line: 11        : CALL               : hi.cbl */
  cob_procedure_params[0] = &f_8;
  cob_glob_ptr->cob_call_params = 1;
  cob_glob_ptr->cob_stmt_exception = 0;
  if (unlikely((cob_glob_ptr->cob_exception_code & 0x0b00) == 0x0b00)) cob_glob_ptr->cob_exception_code = 0;
    if (unlikely(call_greeet.funcvoid == NULL || cob_glob_ptr->cob_physical_cancel))
  {
    call_greeet.funcvoid = cob_resolve_cobol ("greeet", 0, 1);
  }
  b_2 = ((int (*)(void *))call_greeet.funcint) (b_8);

  /* Line: 12        : CALL               : hi.cbl */
  cob_procedure_params[0] = &f_9;
  cob_glob_ptr->cob_call_params = 1;
  cob_glob_ptr->cob_stmt_exception = 0;
  if (unlikely((cob_glob_ptr->cob_exception_code & 0x0b00) == 0x0b00)) cob_glob_ptr->cob_exception_code = 0;
    if (unlikely(call_greeet.funcvoid == NULL || cob_glob_ptr->cob_physical_cancel))
  {
    call_greeet.funcvoid = cob_resolve_cobol ("greeet", 0, 1);
  }
  b_2 = ((int (*)(void *))call_greeet.funcint) (b_9);

  /* Program exit */

  /* Decrement module active count */
  if (module->module_active) {
  	module->module_active--;
  }

  /* Pop module stack */
  cob_module_leave (module);

  /* Program return */
  return b_2;
  P_cgerror:
  	cob_fatal_error (COB_FERROR_CODEGEN);


  /* Program initialization */
  P_initialize:

  cob_check_version (COB_SOURCE_FILE, COB_PACKAGE_VERSION, COB_PATCH_LEVEL);

  cob_module_path = cob_glob_ptr->cob_main_argv0;

  hi_module_init (module);

  module->crt_status = NULL;

  /* Initialize cancel callback */
  cob_set_cancel (module);

  /* Initialize WORKING-STORAGE */
  b_2 = 0;
  memcpy (b_8, "005", 3);
  memcpy (b_9, "\303\244", 2);
  memset (b_9 + 2, 32, 4);

  if (0 == 1) goto P_cgerror;
  initialized = 1;
  goto P_ret_initialize;

  P_dump:
    return 0;


  /* CANCEL callback handling */
  P_cancel:

  if (!initialized)
  	return 0;
  if (module && module->module_active)
  	cob_fatal_error (COB_FERROR_CANCEL);

  initialized = 0;

  P_clear_decimal:
  return 0;

}

/* End PROGRAM-ID 'hi' */

/* Initialize module structure for hi */
static void hi_module_init (cob_module *module)
{
  module->module_name = "hi";
  module->module_formatted_date = COB_MODULE_FORMATTED_DATE;
  module->module_source = COB_SOURCE_FILE;
  module->module_entry.funcptr = (void *(*)())hi;
  module->module_cancel.funcptr = (void *(*)())hi_;
  module->module_ref_count = NULL;
  module->module_path = &cob_module_path;
  module->module_active = 0;
  module->module_date = COB_MODULE_DATE;
  module->module_time = COB_MODULE_TIME;
  module->module_type = 0;
  module->module_param_cnt = 0;
  module->ebcdic_sign = 0;
  module->decimal_point = '.';
  module->currency_symbol = '$';
  module->numeric_separator = ',';
  module->flag_filename_mapping = 1;
  module->flag_binary_truncate = 1;
  module->flag_pretty_display = 1;
  module->flag_host_sign = 0;
  module->flag_no_phys_canc = 1;
  module->flag_main = 1;
  module->flag_fold_call = 0;
  module->flag_exit_program = 0;
  module->flag_debug_trace = 0;
  module->flag_dump_ready = 0;
  module->module_stmt = 0;
  module->module_sources = NULL;
}

/* PROGRAM-ID 'greeet' */

/* ENTRY 'greeet' */

int
greeet (cob_u8_t *b_18)
{
  /* Get current number of call parameters,
     if the parameter count is unknown, set it to all */
  if (cob_get_global_ptr ()->cob_current_module) {
  	cob_call_params = cob_get_global_ptr ()->cob_call_params;
  } else {
  	cob_call_params = 1;
  };

  return greeet_ (0, b_18);
}

static int
greeet_ (const int entry, cob_u8_t *b_18)
{
  /* Program local variables */
  #include "hi.c.l2.h"

  /* Start of function code */

  /* CANCEL callback */
  if (unlikely(entry < 0)) {
  	if (entry == -10)
  		goto P_dump;
  	if (entry == -20)
  		goto P_clear_decimal;
  	goto P_cancel;
  }

  /* Check initialized, check module allocated, */
  /* set global pointer, */
  /* push module stack, save call parameter count */
  if (cob_module_global_enter (&module, &cob_glob_ptr, 0, entry, 0))
  	return -1;

  /* Set address of module parameter list */
  module->cob_procedure_params = cob_procedure_params;

  /* Set frame stack pointer */
  frame_ptr = frame_stack;
  frame_ptr->perform_through = 0;
  frame_ptr->return_address_ptr = &&P_cgerror;

  /* Initialize rest of program */
  if (unlikely(initialized == 0)) {
  	goto P_initialize;
  }
  P_ret_initialize:

  /* Increment module active */
  module->module_active++;

  /* Set not passed parameter pointers to NULL */
  switch (cob_call_params) {
  case 0:
  	b_18 = NULL;
  /* Fall through */
  default:
  	break; 
  }

  /* Store last parameters for possible later lookup */
  last_b_18 = b_18;

  /* Entry dispatch */
  goto l_5;

  /* PROCEDURE DIVISION */

  /* Line: 21        : Entry     greeet                  : hi.cbl */
  l_5:;

  /* Line: 22        : DISPLAY            : hi.cbl */
  cob_display (0, 1, 3, &c_2, COB_SET_DATA (f_18, b_18), &c_3);

  /* Program exit */

  /* Decrement module active count */
  if (module->module_active) {
  	module->module_active--;
  }

  /* Pop module stack */
  cob_module_leave (module);

  /* Program return */
  return b_12;
  P_cgerror:
  	cob_fatal_error (COB_FERROR_CODEGEN);


  /* Program initialization */
  P_initialize:

  cob_check_version (COB_SOURCE_FILE, COB_PACKAGE_VERSION, COB_PATCH_LEVEL);

  cob_module_path = cob_glob_ptr->cob_main_argv0;

  greeet_module_init (module);

  module->crt_status = NULL;

  /* Initialize cancel callback */
  cob_set_cancel (module);

  /* Initialize WORKING-STORAGE */
  b_12 = 0;

  if (0 == 1) goto P_cgerror;
  initialized = 1;
  goto P_ret_initialize;

  P_dump:
    return 0;


  /* CANCEL callback handling */
  P_cancel:

  if (!initialized)
  	return 0;
  if (module && module->module_active)
  	cob_fatal_error (COB_FERROR_CANCEL);

  b_12 = 0;
  cob_module_free (&module);

  initialized = 0;

  P_clear_decimal:
  return 0;

}

/* End PROGRAM-ID 'greeet' */

/* Initialize module structure for greeet */
static void greeet_module_init (cob_module *module)
{
  module->module_name = "greeet";
  module->module_formatted_date = COB_MODULE_FORMATTED_DATE;
  module->module_source = COB_SOURCE_FILE;
  module->module_entry.funcptr = (void *(*)())greeet;
  module->module_cancel.funcptr = (void *(*)())greeet_;
  module->module_ref_count = NULL;
  module->module_path = &cob_module_path;
  module->module_active = 0;
  module->module_date = COB_MODULE_DATE;
  module->module_time = COB_MODULE_TIME;
  module->module_type = 0;
  module->module_param_cnt = 1;
  module->ebcdic_sign = 0;
  module->decimal_point = '.';
  module->currency_symbol = '$';
  module->numeric_separator = ',';
  module->flag_filename_mapping = 1;
  module->flag_binary_truncate = 1;
  module->flag_pretty_display = 1;
  module->flag_host_sign = 0;
  module->flag_no_phys_canc = 1;
  module->flag_main = 1;
  module->flag_fold_call = 0;
  module->flag_exit_program = 0;
  module->flag_debug_trace = 0;
  module->flag_dump_ready = 0;
  module->module_stmt = 0;
  module->module_sources = NULL;
}

/* End functions */

