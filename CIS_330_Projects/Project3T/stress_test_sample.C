#include <PNMreader.h>
#include <PNMwriter.h>
#include <filter.h>
#include <logging.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using std::cerr;
using std::endl;
using std::ofstream;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <username>" << endl;
        exit(EXIT_FAILURE);
    }

    char event[1024];
    sprintf(event, "Entered program from %s\n", argv[1]);
    Logger::LogEvent(event);



    /* ================================ */
    /* START STUDENT MODIFIABLE SECTION */
    /* ================================ */

    /* you may want one or more readers! */
    PNMreader reader("../images/deschutes.pnm");  // note: filename must be "../images/image_name.pnm"

    Shrinker s;
    Shrinker s2;
    Shrinker s3;
    Shrinker s4;
    Shrinker s5;
    Shrinker s6;
    Shrinker s7;
    Shrinker s8;
    Shrinker s9;
    Shrinker s10;

    s.SetInput(reader.GetOutput());  // this test creates a valid image
    s2.SetInput(s.GetOutput());
    s3.SetInput(s2.GetOutput());
    s4.SetInput(s3.GetOutput());
    s5.SetInput(s4.GetOutput());
    s6.SetInput(s5.GetOutput());
    s7.SetInput(s6.GetOutput());
    s8.SetInput(s7.GetOutput());
    s9.SetInput(s8.GetOutput());
    s10.SetInput(s9.GetOutput());


    /* make "finalImage" be the image at the bottom of your pipeline */
    /* the code below will call update on finalImage                 */
    Image *finalImage = s10.GetOutput();

    /* ================================ */
    /*  END STUDENT MODIFIABLE SECTION  */
    /* ================================ */



    try
    {
        finalImage->Update();
    }
    catch (DataFlowException &)
    {
        ofstream ofile("my_exception");
        if (ofile.fail())
        {
             cerr << "Something is wrong ... can't open my_exception"
                  << " for opening" << endl;
             exit(EXIT_FAILURE);
        }
        ofile << "Exception found!" << endl;
        exit(EXIT_SUCCESS);
    }

    CheckSum cs;
    cs.SetInput(finalImage);
    cs.OutputCheckSum("my_checksum");

    if (argc == 3)
    {
        PNMwriter writer;
        writer.SetInput(finalImage);
        writer.Write("3H.pnm");
    }
    Logger::Finalize();
}
