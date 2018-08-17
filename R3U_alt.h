/* HEAD R3U_alt HHH R3U */
/*==================================================================================================

 ====================================================================================================
File description:

    the H file for R3U_alt

    (1) MACRO definition

    (2) Global variables

    (3) Function declaration

Platform:

    Microsoft Windows XP, Professional Version 2002, Service Pack 3
    MatlabR2007a, version 7.4.0.287, MatlabR2008a 7.6.0.324
    Mathematica6.0.3.0(1048410,1048105)
    Borland C++ 5.5 Free Command Line Tools,
       http://www.borland.com/bcppbuilder/freecompiler/

    Dell Optiplex 740
      AMD Athlon 64x2 Dual
      Core Processor 3800+
       2.00 GHz, 960MB of RAM

Reference:
 [1] MATHEMATICA Documents
     http://reference.wolfram.com
 [2] MATLAB MEX-files Guide
     http://www.mathworks.com/support/tech-notes/1600/1605.html
====================================================================================================
Date         Name                    Description of Change     Email
04-Jul-2010  Yi Chen                 Initial                   leo.chen.yi@gmail.com
$HISTORY$
==================================================================================================*/

/* R3U_alt.H Begin */

/*R3U_alt -- C .h file
#include <cstdlib>
#include <stdio.h>
#include <conio.h>*/

/*R3U_alt -- MATLAB   .h file
#include <math.h>
#include <mex.h>
#include <matrix.h>
*/

/*R3U_mathematica -- C .h file
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdafx.h>
#include <windows.h>*/

/*MATHEMATICA   .h file*/
#include <mathlink.h>

/*MATLAB .h file*/
#include <engine.h>

/**************************  (1) MACRO definition BEGIN ***********************/
/* Define status constant */
#define R3U_STATUS_OK                              MLEOK /* MLEOK = 0 */
#define R3U_STATUS_FAIL                            -1

#define R3U_STATUS_DATA_ACTIVE                      2
#define R3U_STATUS_DATA_INACTIVE                    3

#define R3U_STATUS_INITIAL                         1100
#define R3U_STATUS_DATA_MATLAB_TO_MATHEMATICA      1200
#define R3U_STATUS_DATA_MATHEMATICA_TO_MATLAB      1300

#define R3U_STATUS_MATHLINK_CLOSE                  2400
#define R3U_STATUS_MATHLINK_CLOSE_YES              2500
#define R3U_STATUS_MATHLINK_CLOSE_NO               2600

#define R3U_STATUS_MATHLINK_OPEN                   3700
#define R3U_STATUS_MATHLINK_OPEN_OK                3710
#define R3U_STATUS_MATHLINK_OPEN_FAIL              3720

#define R3U_STATUS_DATA_EVAL                       4800

#define R3U_STATUS_ERROR_INITIALIZE_ENV            5900
#define R3U_STATUS_ERROR_INVALID                   -2
#define R3U_STATUS_ERROR_MEX_ARGUMENT              5920
#define R3U_STATUS_ERROR_MCR_INITIALIZE            5925
#define R3U_STATUS_ERROR_NRHS                      5930
#define R3U_STATUS_ERROR_NLHS_LESS                 5940
#define R3U_STATUS_ERROR_NLHS_MORE                 5941
#define R3U_STATUS_ERROR_NLHS                      5942
#define R3U_STATUS_ERROR_PRHS                      5950
#define R3U_STATUS_ERROR_PRHS_NUMBER               5951
#define R3U_STATUS_ERROR_PLHS                      5960
#define R3U_STATUS_ERROR_MXGETSTRING               5970
#define R3U_STATUS_ERROR_MXCREATSTRING             5980
#define R3U_STATUS_ERROR_DEAD_MLINK                5980 + MLEDEAD /* MLEDEAD = 1 */
#define R3U_STATUS_ERROR_NULL_MLINK                R3U_STATUS_ERROR_DEAD_MLINK + 10
#define R3U_STATUS_ERROR_NULL_CSTR                 5810
#define R3U_STATUS_ERROR_PKT_ILLEGALPKT            5820

#define R3U_STATUS_ERROR_MATLAB_ENGINE_NULL        5110

/* unable to establish communication through an opened mathlink */
#define R3U_STATUS_ERROR_UNABLE_ESTABLISH_COMMUNICATION    5830

#define R3U_REGISTERED_EXIT_FUNCTION_YES           6100
#define R3U_REGISTERED_EXIT_FUNCTION_NO            6200

#define R3U_STATUS_HELP                            7000

#define R3U_INPUT_CSTR_WITH_OUTPUT                 R3U_STATUS_DATA_ACTIVE
#define R3U_INPUT_CSTR_WITHOUT_OUTPUT              R3U_STATUS_DATA_INACTIVE

#define R3U_IN_DEBUG_STATUS_YES                    R3U_STATUS_DATA_ACTIVE
#define R3U_IN_DEBUG_STATUS_NO                     R3U_STATUS_DATA_INACTIVE

#define R3U_INPUT_TYPE_UNKNOWN                     8000
#define R3U_INPUT_TYPE_GENERAL                     8100
#define R3U_INPUT_TYPE_FILE                        8200

#define R3U_OUTUT_TYPE_NULL                        8300

/**************************  (1) MACRO definition END  ***********************/

/**************************  (2) Global variables BEGIN *********************/

int R3U_is_registered_exit_function = R3U_REGISTERED_EXIT_FUNCTION_YES;
                                      /*6100*/
int R3U_close_link                  = R3U_STATUS_MATHLINK_CLOSE_NO;

/* replace show_ps_msg or not?*/
int R3U_PS_piece                    = R3U_STATUS_DATA_ACTIVE;

/*
R3U_IN_DEBUG_STATUS_YES - Display debug information
R3U_IN_DEBUG_STATUS_NO  - Do not display debug information */
int R3U_debug_status                = R3U_IN_DEBUG_STATUS_NO;

int R3U_debug_point                 = 0;

static enum { expression_input,
	          string_input
	          } R3U_input_mode;

int R3U_data_to_mathematica_type    = R3U_INPUT_TYPE_GENERAL;

char *R3U_alt_matlab_output  = NULL;

MLINK  R3ULINK_link                 = NULL; /* ONLY one gobal MLINK is allowed, currently */
FILE  *R3ULINK_ps_file              = NULL; /*PostScript graphic file, .ps*/


/*
 * if a few of MATLABs need to run under one MATHEMATICA kernel,
   we need to expand this Engine.
 */

Engine *R3ULINK_engine              = NULL;
/**************************  (2) Global variables END ***********************/


/**************************  (3) Function declaration BEGIN *****************/

#ifndef __FUNCTION_H
#define __FUNCTION_H
/* R3U_mathematicacall */
extern void callmatlab(void);

#endif

/**************************  (3) Function declaration END *****************/

/* R3U_alt.H End */


