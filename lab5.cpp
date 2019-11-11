#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>



int main (int argc, char **argv)
{
  int var;
  int help = 0, version = 0, list = 0, file = 0, information = 0;
 

  while (true)
    {
      static struct option long_options[] =
        {
          {"help",     no_argument, 0, 'h'},
          {"version",  no_argument,0, 'v'},
          {"list",  no_argument, 0, 'l'},
          {"file",    no_argument, 0, 'f'},
	  	  {"information",no_argument,0,'i'}
        };
      
      int option_index = 0;

      var = getopt_long (argc, argv, "ihvlf",
                       long_options, &option_index);

     
      if (var == -1)
        break;

      switch (var)
        {

        case 'help':
	  if (help == 0) {
          	puts ("Args: Help");
		help = 1;
	  }
          break;


	case 'information':
	  if(information == 0){
	  	puts("Args: Information");
		information = 1;
		
	  }
	  break;

        case 'version':
	  if (version == 0) {
          	puts ("Args: Version");
		version = 1;
	  }
          break;

        case 'list':
	  if (list == 0) {
          	puts("Args: List");
		list = 1;
        	
	  }	
	  break;

        case 'file':
	  if (file == 0) {
          	puts("Args: File");
          	file = 1;
		
	  }	
	  break;


        case '?':
          break;

        default:
          break;
        }
    }

  

  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}
