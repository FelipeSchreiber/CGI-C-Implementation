#include "fsfUmlUserInterface.h"
#include <stdio.h>

int main()
{
printf("%s",FsfUmlGetCliUserInterfaceMessage (0,0));
printf("%s",FsfUmlGetCliUserInterfaceMessage (0,1));
printf("%s",FsfUmlGetCliUserInterfaceMessage (0,0));

return 0;
}
