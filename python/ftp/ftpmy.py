from ftplib import FTP_TLS
ftps = FTP_TLS('202.157.143.104:12126')
ftps.login()
ftps.prot_p()
ftps.retrlines('LIST')
