#pragma once

template<typename T> absT(const T & v)
{
	return (v < 0) ? -v : v;
}