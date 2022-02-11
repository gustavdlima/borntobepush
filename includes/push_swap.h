#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define RESET   "\033[0m"		 /* Reset color to default */
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
# define n100	"979 163 4 548 351 543 843 192 35 295 299 741 711 552 495 943 986 36 501 425 419 400 606 187 544 693 836 317 850 269 848 408 522 602 29 933 464 809 437 788 782 313 44 909 698 273 147 605 565 865 469 560 558 47 45 190 505 460 872 76 852 906 874 259 894 770 353 67 750 301 456 980 224 702 346 319 343 98 877 818 9 118 116 393 758 829 444 330 477 39 931 127 575 155 785 757 148 206 652 934"

# define n500	"600 407 612 123 413 165 786 494 355 787 16 724 350 450 499 251 565 451 111 676 3 389 671 198 445 782 578 581 229 58 448 594 685 440 149 40 375 87 464 306 178 103 414 226 763 383 317 611 326 293 760 112 526 287 462 750 346 792 759 580 313 415 43 456 665 344 304 535 128 107 485 217 424 50 453 561 334 332 127 556 386 311 647 219 404 197 755 115 762 670 596 709 373 420 521 209 693 68 296 549 10 584 713 745 33 363 262 152 496 194 187 409 331 333 136 701 196 121 675 30 41 728 488 748 781 119 610 405 290 403 381 131 374 686 729 93 512 625 233 532 117 418 736 789 592 758 459 402 553 622 349 278 703 32 216 261 99 54 422 361 623 447 524 298 70 190 653 49 218 364 150 563 476 144 19 137 511 708 342 199 646 376 329 576 315 202 601 527 378 433 336 490 369 735 784 655 498 400 714 86 6 295 706 14 749 321 628 569 96 371 457 201 606 325 51 130 586 534 654 172 508 66 224 662 663 644 678 189 259 365 173 316 98 692 421 470 5 263 544 243 687 458 522 651 785 531 182 573 7 439 477 474 166 444 401 314 436 778 249 225 17 61 510 754 90 72 339 186 555 384 291 540 509 228 163 200 602 411 502 791 751 519 460 738 635 467 253 279 589 88 630 604 184 153 629 12 385 568 617 204 587 288 114 239 44 100 322 716 493 302 577 330 170 146 739 772 312 105 135 388 8 766 790 351 35 347 700 614 167 20 362 181 269 275 681 657 773 483 618 55 294 343 246 360 134 732 799 690 148 796 75 642 744 156 742 18 585 301 157 438 309 767 234 430 108 546 192 133 638 461 659 116 454 425 235 81 473 609 94 264 621 788 284 354 431 282 160 680 525 507 65 151 241 28 297 775 452 677 248 557 142 639 648 396 73 435 238 118 320 631 542 682 446 747 52 608 764 176 505 551 352 688 140 203 689 122 11 335 394 449 230 60 768 536 783 125 39 640 562 752 740 776 183 77 798 79 725 106 104 62 720 660 267 495 244 154 398 666 529 746 227 472 370 650 372 307 482 139 753 504 769 479 143 465 36 180 620 48 491 489 59 727 305 731 588 85 280 486 24 779 83 323 26 575 208 191 42 82 697 574"

# include "libft.h"
# include <stdio.h>

typedef struct s_doubly_list{
	int						content;
	int						index;
	struct s_doubly_list	*next;
	struct s_doubly_list	*prev;
}				t_doubly_list;

typedef struct s_stacks{
	int				stack_size;
	t_doubly_list	*stack_a;
	t_doubly_list	*stack_b;
	int				*max_values;
}				t_stacks;

// -------------------------------------------- UTILS
// list_utils.c
t_doubly_list	*ft_doubly_lstlast(t_doubly_list *lst);
void			ft_doubly_lstadd_front(t_doubly_list **lst, t_doubly_list *new);
void			ft_doubly_lstadd_back(t_doubly_list **lst, t_doubly_list *new);
t_doubly_list	*ft_doubly_lstnew(int content);
int				ft_doubly_lstsize(t_doubly_list *lst);

// push_swap_utils.c
void			normalize(t_stacks *stacks);
void			initialise(t_stacks *stacks);
int				is_sorted_asc(t_doubly_list *stack);
void			free_stack(t_doubly_list *stack);
void			free_stacks(t_stacks *stacks);

// -------------------------------------------- VALIDATIONS
// validation_utils.c
int				validate_input(t_stacks *stacks, int argc, char *argv[]);

// -------------------------------------------- PUSH SWAP
// push_swap.c
void			push_swap(t_stacks *stacks);
// sort.c
void	sort(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
int		find_index(t_stacks *stacks, int index_size);
void	send_to_top_a(t_stacks *stacks, int index);
void	big_sort(t_stacks *stacks);
// sort_utils.c

int	ft_sqrt(int nb);
int	split_in_groups(t_stacks *stacks);

// -------------------------------------------- OPERATION SWAP
// operations_swap.c
void			sa(t_stacks *stacks, int flag);
void			sb(t_stacks *stacks, int flag);
void			ss(t_stacks *stacks);

// operation_push.c
void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);

// operation_rotate.c
void			ra(t_stacks *stacks, int flag);
void			rb(t_stacks *stacks, int flag);
void			rr(t_stacks *stacks);

// operation_reverse_rotate.c
void			rra(t_stacks *stacks, int flag);
void			rrb(t_stacks *stacks, int flag);
void			rrr(t_stacks *stacks);

// -------------------------------------------- TESTS
void			print_stack(t_doubly_list *stack);
void			print_stacks(t_stacks *stacks);

#endif
