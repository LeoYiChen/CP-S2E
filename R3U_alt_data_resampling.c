/* HEAD R3U_alt_data_resampling CCC 3U */
/*==================================================================================================

 ====================================================================================================
File description:

    R3U_alt_data_resampling.c , This is a file for resampling 

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

Additional information:

(1) Entry function
 *      1)  mexFunction() - R3U_alt_data_resampling Matlab Main Entrance

(2) Static internal functions:
*       1)  SMAT__pkt_handling_0_default()
*       2)  SMAT__pkt_handling_1_BEGINDLGPKT()
*
*       24) SMAT__matlabcall_data_packet_types_handling()
*       25) SMAT__matlabcall_data_send_to_mathematica()
*       26) SMAT__matlabcall_ask_input_type()
*       27) SMAT__matlabcall_replace_substring()

(3) Static functions:
 *      1)  R3U_alt_data_resampling_mathlink_open()
 *      2)  R3U_alt_data_resampling_mathlink_close()
 *      3)  R3U_alt_data_resampling_mathlink_close_must()

(4) Problems Reporting List, TODOLIST
 *      1) Check input mode
 *      2) R3U_alt_data_resampling('TraditionalForm[D[f[x, y], {x, 2}, {y, 3}]]');

(5) Reference
 [1] MATHEMATICA Documents
     http://reference.wolfram.com

 [2] MATLAB MEX-files Guide
     http://www.mathworks.com/support/tech-notes/1600/1605.html

 [3] sprintf() in matlab
     http://www.mathworks.com/access/helpdesk/help/techdoc/index.html?/access/helpdesk/help/techdoc/ref/sprintf.html

====================================================================================================
Date          Name         Description of Change   Email
04-Aug-2008   Yi Chen      Initial                 leo.chen.yi@gmail.com

$HISTORY$
==================================================================================================*/

/*System*/
#include <windows.h>

/*Matlab   .h file*/
#include <math.h>
#include <mex.h>
#include <matrix.h>

/*#include "mclmcr.h" 	*/
/*MATHEMATICA   .h file
#include <mathlink.h>*/

/*SMATLINK   .h file*/
#include "smatlink.h"

/* the difference between #include "*.h" and #include <*.h>
1) #include "R3U_alt_data_resampling.h"
 the compiler will search R3U_alt_data_resampling.h in current work path first, if not find it, then search other given path

2) #include <R3U_alt_data_resampling.h>
 *the compiler will search R3U_alt_data_resampling.h ONLY in given work path
 *e.g. if R3U_alt_data_resampling.h in \include folder or in same path as R3U_alt_data_resampling.c,
 *      #include "R3U_alt_data_resampling.h" can build passed..
 *      BUT R3U_alt_data_resampling.h is ONLY in current work path same as R3U_alt_data_resampling.c,
        #include <R3U_alt_data_resampling.h> can build passed..
 */
 
/************************ Static internal functions list BEGIN ***********************/
/*-------------------------------------------------------------------------
* SMAT__pkt_handling_0_default
* Description:
*              to handle default pkt type
*
* Input:  int  pkt_type_default, Not one of the 22 std. packet types
*
* Output: int *do_evaluate
*
* Return: int status :       SMAT_STATUS_OK  -- ok, go ahead
*                          ! SMAT_STATUS_OK  -- fail
*
* Additional notes:
*
* Totally, 22 packet types
*
* http://reference.wolfram.com/mathematica/ref/c/MLNextPacket.html
*-------------------------------------------------------------------------
* Revision:
* DATE         WHO                    REASON
* 21-May-2008  Yi Chen                Initial
*-------------------------------------------------------------------------*/
static int SMAT__pkt_handling_0_default
(
	int  pkt_type_default, /*I*/
	int *do_evaluate       /*O*/
);


/************************ Static  functions list END ***********************/

/************************ Main Entry Function to Matlab BEGIN******************/
/*-------------------------------------------------------------------------
* mexFunction
*
* Description:  Mainfunction - Entry point to C MEX-file
*               mexFunction Name of the gateway routine (same for every MEX-file)
*
*               R3U_alt_data_resampling Matlab Main Entrance
*
* Input:
* nrhs -- Number of matlab INPUT (Right Hand Side of Matlab function )
* prhs -- Array of pointers to INPUT data.
*         The input data is read-only and should not be altered by your mexFunction .
*
* Output:
* nlhs -- Number of expected mxArrays,matlab OUTPUT (Left Hand Side of Matlab function )
* plhs -- Array of pointers to expected OUTPUT
*
* Return: void
*
* More information:
* 1) Mex
* http://www.mathworks.com/access/helpdesk/help/techdoc/index.html?/access/helpdesk/help/techdoc/apiref/mexfunction.html&http://www.mathworks.com/cgi-bin/texis/webinator/search/?db=MSS&prox=page&rorder=750&rprox=750&rdfreq=500&rwfreq=500&rlead=250&sufs=0&order=r&is_summary_on=1&ResultCount=10&query=mexFunction&submitButtonName=Search
*
* http://www.mathworks.com/support/tech-notes/1600/1605.html
* http://www.mathworks.co.uk/support/tech-notes/1600/1605.html
*
* Section 10: mexFunction gateway
* The gateway routine to every MEX-file is called mexFunction. This is the entry point MATLAB uses to access the DLL.
*
* http://www.mathworks.com/access/helpdesk/help/techdoc/index.html?/access/helpdesk/help/techdoc/apiref/mexfunctionname.html&http://www.mathworks.com/cgi-bin/texis/webinator/search/
* mexFunction is not a routine you call. Rather, mexFunction is the name of a function in C (subroutine in Fortran) that you must write in every MEX-file. When you invoke a MEX-function, MATLAB¢n software finds and loads the corresponding MEX-file of the same name. MATLAB then searches for a symbol named mexFunction within the MEX-file. If it finds one, it calls the MEX-function using the address of the mexFunction symbol. If MATLAB cannot find a routine named mexFunction inside the MEX-file, it issues an error message.
*
* When you invoke a MEX-file, MATLAB automatically seeds nlhs, plhs, nrhs, and prhs with the caller's information. In the syntax of the MATLAB language, functions have the general form:
*
*[a,b,c,...] = fun(d,e,f,...)where the ... denotes more items of the same format. The a,b,c... are left-hand side arguments, and the d,e,f... are right-hand side arguments. The arguments nlhs and nrhs contain the number of left-hand side and right-hand side arguments, respectively, with which the MEX-function is called. prhs is an array of mxArray pointers whose length is nrhs. plhs is an array whose length is nlhs, where your function must set pointers for the returned left-hand side mxArrays.
*
* 2) Mathlink
* http://reference.wolfram.com/mathematica/tutorial/RunningMathematicaFromWithinAnExternalProgram.html
*
* Running Mathematica from Within an External Program
* To run Mathematica from within an external program requires making use of many general features of MathLink. The first issue is how to establish a MathLink connection to Mathematica.
* When you use MathLink templates to create external programs that can be called from Mathematica, source code to establish a MathLink connection is automatically generated, and all you have to do in your external program is to call MLMain(argc, argv). But in general you need to call several functions to establish a MathLink connection.

* MLENVMLInitialize(0)
*				  initialize MathLink library functions

* MLINKMLOpenArgcArgv(MLENV env,int argc,char**argv,int*errno)
*                 open a MathLink connection taking parameters from an argv array

* MLINKMLOpenString(MLENV env,char*string,int*errno)
*                 open a MathLink connection taking parameters from a single character string

* int MLActivate(MLINK link)
                  activate a MathLink connection, waiting for the program at the other end to respond
* void MLClose(MLINK link)
*                 close a MathLink connection

* void MLDeinitialize(MLENV env)
*                 deinitialize MathLink library functions
*
* 3)Connection Technologies Workshop
*   http://library.wolfram.com/infocenter/Conferences/6595/
*
* Revision:
* DATE         WHO                    REASON
* 21-Jan-2008  Yi Chen                Initial
* 02-Sep-2008  Yi Chen                replace MLInitialize() with
*                                             MLInitialize((MLParametersPointer)0)
* 12-Sep-2008  Yi Chen                Fix Assertion failed: Forced Assertion at line 714 of file ".\memmgr\mem32aligned.cpp".
*                                     Corrupted memory block found, with following stack track information:
*                                     [0] mcr.dll:...., mxDestroyArray() related issue.
*-------------------------------------------------------------------------*/
void mexFunction
(
	int            nlhs,  /*O*/
	mxArray       *plhs[],/*O*/
	int            nrhs,  /*I*/
	const mxArray *prhs[] /*I*/
)
{


	return status;
}


/*-------------------------------------------------------------------------
* SMAT__matlabcall_replace_substring
* Description:
*   replace an old substring by a new substring , in a source string, and
*   generate a new source string
*
* Input:       char  *source_string,
*              char  *old_sub_str
*              char  *new_sub_str
*              char **new_source_str
*
* Output:      status
*
* Return: int status :      SMAT_STATUS_OK
*                           SMAT_STATUS_FAIL
*
*
* Additional notes:
* 1) mexCallMATLAB (C and Fortran)
*  http://www.mathworks.com/access/helpdesk/help/techdoc/index.html?/access/helpdesk/help/techdoc/ref/f16-6011.html&http://www.mathworks.com/cgi-bin/texis/webinator/search/?db=MSS&prox=page&rorder=750&rprox=750&rdfreq=500&rwfreq=500&rlead=250&sufs=0&order=r&is_summary_on=1&ResultCount=10&query=strrep+mex
*   #include "mex.h"
*   int mexCallMATLAB( int         nlhs,
*                      mxArray    *plhs[],
*                      int         nrhs,
*                      mxArray    *prhs[],
*                      const char *name);
*
* e.g.    print out eigenvalue matrix
*         mexCallMATLAB(0,NULL,1, &lhs[1], "disp");
* 2)
* strdup - duplicate a string
*
* #include <string.h>
*
* char *strdup(const char *s1);
*
*-------------------------------------------------------------------------
* Revision:
* DATE         WHO                    REASON
* 08-Jul-2008  Yi Chen                Initial
*-------------------------------------------------------------------------*/
static int SMAT__matlabcall_replace_substring
 (
char   *source_string,  /*I*/
char   *old_sub_str,    /*I*/
char   *new_sub_str,    /*I*/
char  **new_source_str  /*OF*/
)
{
      /*initialize*/
      char   *temp_pointer_1 = NULL;
      char   *temp_pointer_2 = NULL;
      char   *temp_pointer_3 = NULL;

      int   old_sub_len = 0;
      int   new_sub_len = 0;
      int   status      = SMAT_STATUS_INITIAL;

      if(( old_sub_str   == NULL )  ||
         ( new_sub_str   == NULL )  ||
         ( source_string == NULL )
        )
      {
          status = SMAT_STATUS_FAIL;

          return status;
        }

   

        status = SMAT_STATUS_OK;

        return   status;
  }

/************************** Static interal Functions END ****************************/

/* R3U_alt_data_resampling END */

