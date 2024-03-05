#pragma once

class Buffer {
public:
	virtual void unbind_buffer() const = 0;
	virtual void delete_buffer() const = 0;
};