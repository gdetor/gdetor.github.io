/*****************************************************************************
* Copyright (c) 2011, Georgios Is. Detorakis
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY Georgios Is. Detorakis ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Georgios Is. Detorakis BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* -----------------------------------------------------------------------------
* Contributor:
*
*     Georgios Detorakis
*
* Contact Information:
*
*     Georgios Is. Detorakis
*     INRIA Nancy - Grand Est research center
*     CS 20101
*     54603 Villers les Nancy Cedex France
*/
#include <stdio.h>
#include <stdlib.h>
void print_buffer( void *, int );
void catbin( char * );

/*****************************************************************************
* Main  function of the bincat program. 
******************************************************************************/
int main( int argc, char **argv )
{
	if ( argc == 2 ){ catbin( argv[1] ); }
	else{
		printf("You must type the name of the file!\n");
		printf("Example: bincat foo.dat \n");
	}

	return 0;
}

/*****************************************************************************
* print_buffer function takes as input a pointer of type void (buffer) and
* the size of the buffer and it prints the data contained in it. 
*****************************************************************************/
void print_buffer( void *buffer, int buffer_size )
{
	int i;

	for ( i = 0; i < buffer_size; ++i ){
		printf( "%c", (( char * )buffer)[i] );
	}
	printf( "\n" );
}

/*****************************************************************************
* catbin function takes as input the name of a binary file and cats the data
* contained in that file. 
******************************************************************************/
void catbin( char *filename )
{
	FILE *fp; /* Pointer to the input binary file. */
	int fileLen; /* File length. */
	char *buffer; /* Buffer for temporary storage. */ 

	/* Openning the input binary file and check if the file exists. */
	if ( !( fp = fopen( filename, "rb" ) ) ){
		printf("File does not exist!\n");
		exit(-1);
	}

	/* Calculate the length of the input binary file. */
	fseek( fp, 0, SEEK_END );
	fileLen = ftell( fp ); /* The current value of the position indicator. */
	fseek( fp, 0, SEEK_SET );

	/* Memory allocation of the buffer. */
	buffer = ( char * )malloc( fileLen + 1  );

	/* Read the data from the input binary file and store them temporaly to the buffer. */
	fread( buffer, fileLen, 1, fp );
	fclose( fp );

	/* Print the data on the standard output. */
	print_buffer( buffer, fileLen+1 );

	/* Free allocated memory of the buffer. */
	free( buffer );
}
