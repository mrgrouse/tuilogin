#include <form.h>

int main()
{
	FIELD *field[3];
	FORM  *login_form;
	int row, col;
	char user[32];
	char password[255];

	initscr(); // initialize
	cbreak(); // fix tty from 'cooked' mode
	getmaxyx(stdscr, row, col); // getting the max rows & columns
	noecho(); // disable general echoing
	keypad(stdscr, TRUE); // setup keyboard
	//WINDOW *formwin = subwin()

	int prow = row / 2; // centered prompt row y
	int pcol = col / 2;  // centered prompt col x

	/* Initialize the fields */
	/* new_field(height, width, topleft row, topleft column, off-screen rows, additional buffers) */
	field[0] = new_field(1, 10, prow, pcol, 0, 0);
	field[1] = new_field(1, 10, prow + 2, pcol, 0, 0);
	field[2] = NULL;

	/* Set field options */
	set_field_back(field[0], A_UNDERLINE); 	// Print a line for the option
	field_opts_off(field[0], O_AUTOSKIP);  	// Don't go to next field when filled
	set_field_back(field[1], A_UNDERLINE);
	field_opts_off(field[1], O_AUTOSKIP);

	/* Create the form and post it */
	login_form = new_form(field);
	post_form(login_form);
	mvprintw(prow, pcol - 9, "Username:");
	mvprintw(prow + 2, pcol - 9, "Password:");
	move(prow, pcol);
	box(stdscr, ACS_VLINE, ACS_HLINE);
	refresh();
	// TODO: open fd3 and send \n for readiness notification
	echo();
	getstr(user);

	/*
	if (strlen(user) > 32)
		goto overflow;
	if (strlen(password) > 255)
		goto overflow;
	*/

	move(prow + 2, pcol);
	getstr(password);
	noecho();

	unpost_form(login_form);
	free_form(login_form);
	free_field(field[0]);
	free_field(field[1]);

	endwin();

	return 0;
}
