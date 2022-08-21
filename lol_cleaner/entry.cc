#include "inc.hh"

int main( )
{
	// Console title
	//
	SetConsoleTitle( "notfeels/lol_cleaner" );

	// Hello 
	//
	std::cout << "Beginning lol_cleaner\n\n";

	// close processes
	//
	process::close_all( );

	// clear logs
	//
	files::clear_logs( );

	// Bye 
	//
	std::cout << "You can play now! GLHF :)";
	std::this_thread::sleep_for( std::chrono::seconds( 6 ) );

	return EXIT_SUCCESS;
}