#include <iostream>

int main()
{
	char s[255];
	char s1[255];
	char f[] = "%s";
	char fd[] = "%d\n";

	__asm {
		lea eax, s
		push eax
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		lea eax, s1
		push eax
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		lea eax, s
		dec eax
		mov ecx, 0
		dec ecx

		cnts :
		inc eax
			inc ecx
			cmp[eax], 0
			jnz cnts

			lea ebx, s1
			dec ebx
			mov edx, 0
			dec edx

			cntsub :
		inc ebx
			inc edx
			cmp[ebx], 0
			jnz cntsub


			push edx
			cmp edx, ecx
			jg end1
			cmp edx, 0
			jz end1

			dec eax
			dec ebx

			f1 :
		cmp edx, 0
			jz end2
			cmp ecx, 0
			jz end1
			push ecx
			mov ch, [eax]
			mov cl, [ebx]
			cmp ch, cl
			pop ecx
			jz skip
			pop edx
			lea ebx, s1
			add ebx, edx
			push edx
			dec ebx
			push ecx
			mov ch, [eax]
			mov cl, [ebx]
			cmp ch, cl
			pop ecx
			jz skip
			dec eax
			dec ecx
			jmp f1
			skip :
		dec eax
			dec ebx
			dec ecx
			dec edx
			jmp f1

			end1 :
		mov ecx, -1
			end2 :
			push ecx
			lea ecx, fd
			push ecx
			call printf
			add esp, 12

	}
}