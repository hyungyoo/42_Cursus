#ifndef BASEDIRECTIVES_HPP
#define BASEDIRECTIVES_HPP

#include <vector>
#include <string>

namespace ft
{
	class BaseDirectives 
	{
		protected:
			std::string			root_;
			unsigned long			client_max_body_size_;
			unsigned int			keepalive_timeout_;
			std::vector<std::string>	index_;
			bool				autoindex_;
			std::string			error_page_;
		public:
			BaseDirectives();
			// Getter
			const std::string		getRoot(void) const;
			unsigned long			getClientMaxBodySize(void) const;
			unsigned int			getKeepaliveTimeout(void) const;
			const std::vector<std::string>	getIndex(void) const;
			bool				getAutoindex(void) const;
			const std::string		getErrorPage(void) const;
			
			// Setter
			void				setRoot(const std::string x);
			void				setClientMaxBodySize(const unsigned long x);
			void				setKeepaliveTimeout(const unsigned int x);
			void				setIndex(const std::vector<std::string> x);
			void				setIndex(const std::string x);
			void				setAutoindex(const bool x);
			void				setErrorPage(const std::string x);

			void				clearIndex(void);
	};

}

#endif
