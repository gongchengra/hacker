C     gfortran -o pi.exe %
      implicit real*8(a-h,o-z)
      parameter(nk=10000)
      dimension ns(nk),na1(nk),na2(nk),nt1(nk),nt2(nk),np1(nk),np2(nk)

      do i=1,nk
          ns(i)=0
          na1(i)=0
          na2(i)=0
          nt1(i)=0
          nt2(i)=0
          np1(i)=0
          np2(i)=0
      end do

      nt1(2)=3
      nt1(3)=2
      nt2(2)=4

      do i=2,nk
          na2(i)=nt2(i)
          nd=mod(na2(i-1),239)*10+na2(i)
          nt2(i)=nd/239
          na2(i)=mod(nd,239)
      end do

      do i=1,nk
          ns(i)=ns(i)+nt1(i)
      end do

      do i=nk,2,-1
          ntmp=ns(i)
          if(ntmp.ge.nt2(i)) ns(i)=ns(i)-nt2(i)
          if(ntmp.lt.nt2(i)) then
              ns(i)=ns(i)+10-nt2(i)
              ns(i-1)=ns(i-1)-1
          end if
      end do

      n=1
      nflag=1
      do j=1,nk
          n=n+2
          nflag=-1*nflag

          do i=2,nk
              na1(i)=nt1(i)
              nd=mod(na1(i-1),25)*10+na1(i)
              nt1(i)=nd/25
              na1(i)=mod(nd,25)
          end do

          do i=2,nk
              na1(i)=nt1(i)
              nd=mod(na1(i-1),n)*10+na1(i)
              np1(i)=nd/n
              na1(i)=mod(nd,n)
          end do

          do i=2,nk
              na2(i)=nt2(i)
              nd=mod(na2(i-1),57121)*10+na2(i)
              nt2(i)=nd/57121
              na2(i)=mod(nd,57121)
          end do

          do i=2,nk
              na2(i)=nt2(i)
              nd=mod(na2(i-1),n)*10+na2(i)
              np2(i)=nd/n
              na2(i)=mod(nd,n)
          end do

          if(nflag.lt.0) then
              do i=2,nk
                  ns(i)=ns(i)+np2(i)
              end do
              do i=nk,2,-1
                  ntmp=ns(i)
                  if(ntmp.ge.np1(i)) ns(i)=ns(i)-np1(i)
                  if(ntmp.lt.np1(i)) then
                      ns(i)=ns(i)+10-np1(i)
                      ns(i-1)=ns(i-1)-1
                  end if
                  ns(i-1)=ns(i-1)+ns(i)/10
                  ns(i)=mod(ns(i),10)
              end do
          end if

          if(nflag.gt.0) then
              do i=2,nk
                  ns(i)=ns(i)+np1(i)
              end do
              do i=nk,2,-1
                  ntmp=ns(i)
                  if(ntmp.ge.np2(i)) ns(i)=ns(i)-np2(i)
                  if(ntmp.lt.np2(i)) then
                      ns(i)=ns(i)+10-np2(i)
                      ns(i-1)=ns(i-1)-1
                  end if
                  ns(i-1)=ns(i-1)+ns(i)/10
                  ns(i)=mod(ns(i),10)
              end do
          end if
      end do

      open(60,file="pi.log")
      write(60,'(1a)'),"pi=3."
      write(60,'(50i1)')(ns(i),i=3,nk)
      write(*,'(a)'),'The ten digital primes in pi:'
      write(60,'(a)'),'The ten digital primes in pi:'

      do i=2,nk-10
          mtmp=0
          if (ns(i).ne.0) then
              do j=i,i+9
                  mtmp=mtmp*10+ns(j)
              end do
              nst=int(sqrt(float(mtmp)))
              do it=2,nst
                  if (mod(mtmp,it).eq.0) then
                      goto 13
                  end if
              end do
13            if (it.gt.nst) then
                  write(*,'(i5,i15)'),i,mtmp
                  write(60,'(i5,i15)'),i,mtmp
              end if
          end if
      end do

      close(60)
      stop
      end
