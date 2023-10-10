#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "OpenFile.h"
#include "LoadFileContents.h"
#include "GetNextToken.h"
#include "CheckNewlineInBuffer.h"

int main()
{
    
    int result;
    
    char *inputBuffer = NULL;
    char *outputBuffer = NULL;
    char *token;
    
    OpenFile("input.ls", "r");
    OpenFile("output.ldr", "r");

    LoadFileContents("input.ls", &inputBuffer);
    LoadFileContents("output.ldr", &outputBuffer);
    
    while ((token = GetNextToken(&inputBuffer)) != NULL) {
        printf("Token: %s\n", token);
        token = NULL;
    }
    
    result = CheckNewlineInBuffer(outputBuffer);
    
    free(inputBuffer);
    free(outputBuffer);

    return 0;
}
