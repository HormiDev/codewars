#include <stddef.h>
#include <stdlib.h>

typedef struct prime_stream_t{
  unsigned prime;
  struct prime_stream_t **last_prime_stream;
  struct prime_stream_t *next;
} prime_stream_t;

int is_prime(unsigned n, prime_stream_t *stream)
{
	while (stream) {
		if (n % stream->prime == 0) {
			return 0;
		}
		if (stream->prime * stream->prime > n) {
			return 1;
		}
		stream = stream->next;
	}
	return 1;
}

/* Allocate and initialize a new stream */
prime_stream_t *prime_stream_new(void) 
{
	prime_stream_t *stream = malloc(sizeof(prime_stream_t));
	stream->prime = 0;
	stream->last_prime_stream = malloc(sizeof(prime_stream_t *));
	*stream->last_prime_stream = stream;
	stream->next = NULL;
	return stream;
}

void prime_stream_add_new(prime_stream_t *stream, unsigned prime)
{
	prime_stream_t *new_stream = malloc(sizeof(prime_stream_t));
	prime_stream_t *last_stream = *stream->last_prime_stream;

	new_stream->prime = prime;
	new_stream->last_prime_stream = stream->last_prime_stream;
	new_stream->next = NULL;
	*new_stream->last_prime_stream = new_stream;
	last_stream->next = new_stream;
}

/* Get the next prime in the stream */
unsigned prime_stream_next(prime_stream_t *stream) 
{
	prime_stream_t *last_stream = *stream->last_prime_stream;
	unsigned result = last_stream->prime + 1;

	if (last_stream->prime == 0) {
		stream->prime = 2;
		return 2;
	}
	while (!is_prime(result, stream)) {
		result++;
	}
	prime_stream_add_new(stream, result);
	return result;
}

/* Free your prime stream */
void prime_stream_destroy(prime_stream_t *stream)
{
	prime_stream_t *next;

	while (stream) {
		next = stream->next;
		free(stream);
		stream = next;
	}
}

#include <stdio.h>
int main()
{
	prime_stream_t *stream = prime_stream_new();
	for (int i = 0; i < 1000000; i++) {
		printf("%d\n", prime_stream_next(stream));
	}
	prime_stream_destroy(stream);
	return 0;
}
